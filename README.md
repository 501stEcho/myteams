
# myteams

This project is a replica of the Teams software without the graphic interface made in the C programming language.\
Using the C implementation of sockets, many users can connect at the same time and send each others messages, create teams, create channels...



## Usage/Examples

### Create the binary
```bash
cd myteams

# if you use zsh
echo "export LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:$PWD/libs/myteams/" >> ~/.zshrc

# if you use bash
echo "export LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:$PWD/libs/myteams/" >> ~/.bashrc

make
```


### Launch the server
```bash
./myteams_server [PORT]
```

### Launch the client
```bash
./myteams_cli [IP] [PORT]
```
\
From the client side, you should now be connected and be able to type commands.\
At any given moment, you can use the */help* command to access the list of all available commands.


#### Precisions
All parameters passed with command must be between quotes (").\
There is currently not yet a password/authentification system, that means that users are only identified with their username.

### Login
Log into an existing account or create a new one if the username does not yet exists.
```
/login "[username]"
```

### Logout
Log out of the current user
```
/logout
```

### Users
Get the list of existing users on the server
```
/users
```

### User
Acces details about the requested user
```
/user ["user_uuid"]
```

### Send
Send a message to a specific user
```
/send ["user_uuid"] ["message_body"]
```

### Messages
List all messages exchanged with the specific user
```
/messages ["user_uuid"]
```

### Subscribe
Subscribe to the events of a team and its sub directories (enable reception of all events from a team)
```
/subscribe ["team_uuid"]
```

### Subscribed
List all subscribed teams or list all users subscribed to a team
```
/subscribed ?["team_uuid"]
```

### Unubscribe
Unsubscribe from a team
```
/unsubscribe ["team_uuid"]
```

### Use
Sets the command context to a team / channel / thread
```
/use ?["team_uuid"] ?["channel_uuid"] ?["thread_uuid"]
```

### Create
Based on the context, create the sub resource (see below)
```
/create
```

### List
Based on the context, list all the sub resources (see below)
```
/list
```

### Info
Based on the context, display details of the current resource (see below)
```
/info
```

## Create
When the context is not defined (/use), creates a new team :
```
/create ["team_name"] ["team_description"]
```
When team_uuid is defined (/use “team_uuid”), creates a new channel :
```
/create ["channel_name"] ["channel_description"]
```
When team_uuid and channel_uuid are defined (/use “team_uuid” “channel_uuid”), creates a new thread :
```
/create ["thread_title"] ["thread_message"]
```
When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid” “channel_uuid” “thread_uuid”), creates a new reply :
```
/create ["comment_body"]
```

## List
When the context is not defined (/use), list all existing teams :
```
/list
```
When team_uuid is defined (/use “team_uuid”), list all existing channels :
```
/list
```
When team_uuid and channel_uuid are defined (/use “team_uuid” “channel_uuid”), list all existing threads :
```
/list
```
When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid” “channel_uuid” “thread_uuid”), list all existing replies :
```
/list
```

## Info
When the context is not defined (/use), display currently logged-in user details :
```
/info
```
When team_uuid is defined (/use “team_uuid”), display currently selected team details :
```
/info
```
When team_uuid and channel_uuid are defined (/use “team_uuid” “channel_uuid”), display currently selected channel details :
```
/info
```
When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid” “channel_uuid” “thread_uuid”), display currently selected thread details :
```
/info
```
## Authors

- [@501stEcho](https://github.com/501stEcho)
- [@geoffroy-luc](https://github.com/geoffroy-luc)
- [@WhiiteRose](https://github.com/WhiiteRose)


## Documentation

### REPLY CODES

reply codes represents the answer of the server and is used by the client to adapt its behaviour to the raw data it receives

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

### Possible response codes

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