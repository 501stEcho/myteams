# MYTEAMS EPITECH PROTOCOL (MEP)

Status of this Memo

   This memo is the official specification of the File Transfer
   Protocol (MEP).  Distribution of this memo is unlimited.

   Note that this specification is compatible with the previous edition.
## INTRODUCTION

   The objectives of **MEP** are 1) to promote transfer of information (computer
   programs and/or data), 2) to encourage indirect or implicit (via
   programs) use of remote computers, 3) to shield a user from
   variations in file storage systems among hosts, and 4) to transfer
   data reliably and efficiently.  **MEP**, though usable directly by a user
   at a terminal, is designed mainly for use by programs.

   The attempt in this specification is to satisfy the diverse needs of
   users of maxi-hosts, mini-hosts, personal workstations, and TACs,
   with a simple, and easily implemented protocol design.

   This paper assumes knowledge of the socket usage in the c language.

## OVERVIEW

   In this section, the history, the terminology, and the MEP model are
   discussed.  The terms defined in this section are only those that
   have special significance in MEP.  Some of the terminology is very
   specific to the MEP model; some readers may wish to turn to the
   section on the MEP model while reviewing the terminology.

### **2.1.** HISTORY
    
    The project started the 26/03/2023 and ended 23/04/2023.
    The first version of MEP was released at 23:42 precisely.

### **2.2.** TERMINOLOGY

    **ASCII**

        The ASCII character set is as defined in the ARPA-Internet
        Protocol Handbook.  In MEP, ASCII characters are defined to be
        the lower half of an eight-bit code set (i.e., the most
        significant bit is zero).

    **control connection**

         The communication path between the USER-PI and SERVER-PI for
         the exchange of commands and replies.  This connection follows
         the Telnet Protocol.

    **End-of-Line**

         The end-of-line sequence defines the separation of printing
         lines. The sequence is \r\n and marks the end of the input.

    **MEP commands**

         A set of commands that comprise the control information flowing
         from the user-MEP to the server-MEP process.

    **client**

         A system which sends and receive information by writing and reading
         informations on the server socket. It is attributed an user if it is logged in.
         If not, it is considerer not-logged and doesn't have access to any command except
         login.
        
    **uuid**

        A unique chain of characters which allows the server to identify every entity it owns.

    **user**

        A fictived person which has subscribed team and is attributed a unique uuid. It is
        also identified with a username, set by the client in the login.
    
    **context**

        Represents the *position* of the user in the server structure. It can contain 4 state :
        *home*, *team*, *channel* and *thread*.
        The effects of certain MEP functions can vary according to the context.


### **2.3.** THE MEP MODEL

With the above definitions in mind, the following model (shown in
      Figure 1) may be diagrammed for an MEP service.


*MTP Protocol schema*
```
------------    ----------
| Database |<-->| Backup |
------------    ----------
                     ^
                     |
                     V
                --------------
                | MTP server |---Code and Raw Data---|
                --------------                       V
                     ^                     ------------------      --------      -----------------
                     |<--Requests----------| User interface |<---->| User |<---->| Your business |
                                           ------------------      --------      -----------------
```


*Server system*
```

         Control   -------------  Linked list of command
          -------->| Server    |----------------
          |        -------------               |
          |                              --------------------    
          |                              | Selected command |
    ------------                         --------------------
    | raw data |                                |
    ------------                                V
          ^                                -----------------
          |                                | Client buffer |
    -----------------                      -----------------  
    | /command [...]|                            |
    -----------------                            V
                            -----------------------------------------------
                            | Writing from client buffer to client socket |
                            -----------------------------------------------
                                                 |
                                                 V
                                              --------
                                              | User |
                                              --------
```

To be considered complete, a command sent on the server socket must end with the sequence \r\n,
otherwise it will be stored and merged with the next incoming input.
The same is true for the replies of the server, which must always end with the sequence \r\n.


## MTP FUNCTIONS

In order to correctly execute a function, you must precede it by a slash ('/') and put arguments between double quotes.
In case of invalid format, the server will not execute any command and will ignore it.
The signal codes returned by these functions are mentioned further below.


### help
```
/help
```
show help


### login
```
/login ["user_name"]
```
set the user_name used by client
If the a user with this username does not exists yet, a new one will be created


### logout
```
/logout
```
disconnect the client from the server


### users
```
/users
```
get the list of all users that exist on the domain

### user
```
/user ["user_uuid"]
```
get details about the requested user


### send
```
/send ["user_uuid"] ["message_body]
```
send a message to specific user


### messages
```
/messages ["user_uuid]
```
list all messages exchanged with the specified user


### subscribe
```
/subscribe ["team_uuid]
```
subscribe to the events of a team and its sub directories (enable reception
of all events from a team)


### subscribed
```
/subscribed ?["team_uuid]
```
list all subscribed teams or list all users subscribed to a team


### unsubscribe
```
/unsubscribe ["team_uuid]
```
unsubscribe from a team


### use
```
/use ?["team_uuid"] ?["channel_uuid"] ?["thread_uuid"] 
```
Sets the command context to a team/channel/thread


### create
```
/create
```
based on the context, create the sub resource

When the context is not defined (/use):
    /create \["team_name"] \["team_description"] : create a new team

When team_uuid is defined (/use "team_uuid"):
    /create \["channel_name"] \["channel_description"] : create a new channel

When team_uuid and channel_uuid are defined (/use "team_uuid" "channel_uuid"):
    /create \["thread_title"] \["thread_message"] : create a new thread

When team_uuid, channel_uuid and thread_uuid are defined (/use "team_uuid" "channel_uuid" "thread_uuid"):
    /create \["comment_body"] : create a new reply


### list
```
/list
```
based on the context, list all the sub resources

When the context is not defined (/use):
    /list : list all existing teams

When team_uuid is defined (/use “team_uuid”):
    /list : list all existing channels

When team_uuid and channel_uuid are defined (/use “team_uuid” “channel_uuid”):
    /list : list all existing threads

When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid” “channel_uuid” “thread_uuid”):
    /list : list all existing replies


### info
```
/info
```
based on the context, display details of the current resource

When the context is not defined (/use):
    /info : display currently logged-in user details

When team_uuid is defined (/use “team_uuid”):
    /info : display currently selected team details

When team_uuid and channel_uuid are defined (/use “team_uuid” “channel_uuid”):
    /info : display currently selected channel details

When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid” “channel_uuid” “thread_uuid”):
    /info : display currently selected thread details


## REPLY CODES

reply codes represents the answer of the server and is used by the client to adapt its behaviour
to the raw data it receives

Numeric  Order List of Mandatory Reply Codes (Extract)

    FEATURE:

        100 - Help

        102 - Login Sucess

        103 - Login Fail

        104 - Logout Sucess

        105 - Logout Fail

        106 - Get users list Sucess

        107 - Get users list Fail

        108 - Get specific user detail Sucess

        109 - Get specific user detail Fail

        110 - Send message Sucess

        111 - Send message Fail

        112 - List all Message Sucess

        113 - List all Message Fail

        114 - Subscribe to the events of a team Sucess

        115 - Subscribe to the events of a team Fail

        116 - List all subscribed Sucess

        117 - List all subscribed Fail

        118 - unsubscribe from a team Sucess

        119 - unsubscribe from a team Fail

        120 - Set command context Sucess

        121 - Set command context Fail

    CREATE:
        202 - Create new team Sucess

        203 - Create new team Fail

        204 - Create new channel Sucess

        205 - Create new channel Fail

        206 - Create new thread Sucess

        207 - Create new thread Fail

        208 - Create new reply Sucess

        209 - Create new reply Fail

    LIST:
        302 - list all existing team Sucess

        303 - list all existing team Fail

        304 - list all existing channel Sucess

        305 - list all existing channel Fail

        306 - list all existing thread Sucess

        307 - list all existing thread Fail

        308 - list all existing reply Sucess

        309 - list all existing reply Fail

    INFO:
        402 - display currently logged-in user details Sucess

        403 - display currently logged-in user details Fail

        404 - display currently selected team details Sucess

        405 - display currently selected team details Fail

        406 - display currently selected channel details Sucess

        407 - display currently selected channel details Fail

        408 - display currently selected reply details Sucess

        409 - display currently selected reply details Fail

    ERROR:
        504 - Server Error

        505 - Client Error


## MEP COMMANDS

The following are the MEP commands:

/login <user_name>

/logout

/users

/user <user_uuid>

/send <user_uuid> <message_body]

/messages <user_uuid]

/subscribe <team_uuid]

/subscribed ?<team_uuid]

/unsubscribe <team_uuid]

/use ?<team_uuid> ?<channel_uuid> ?<thread_uuid> 

/create

/list

/info



### MEP COMMANDS ARGUMENTS
<...> ::= mandatory argument; string format surrounded by double quotes

?<...> ::= optional argument; string format surrounded by double quotes


### SEQUENCING OF COMMANDS AND REPLIES
LOGIN

	102
    

LOGOUT

	104
    
	509
    

USERS

	106
    
	509
    

USER

	108
    
	507
    
	509
    

SEND

	110
    
	507
    
	509
    

MESSAGES

	112
    
	507
    
	509
    

SUBSCRIBE

	114
    
	501
    
	509
    

SUBSCRIBED

	116
    
	118
    
	501
    
	509
    

UNSUBSCRIBE

	120
    
	501
    
	509
    

USE

	*On success, no code is returned*
    
	509
    

CREATE

	202
    
	204
    
	206
    
	208
    
	509
    
	511
    

LIST

	302
    
	304
    
	306
    
	308
    
	509
    

INFO

	402
    
	404
    
	406
    
	408
    

REFERENCES

   Paul Laban, "Les sockets en C pour les nuls"

   Tom Roger, "L'art du codage, Sun Tzu"

   Geoffroy Luc, "L'allégorie de la caverne, de Plython le philosophe"
