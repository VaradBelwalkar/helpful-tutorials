### Basic Commands

```
SET key value
GET key
DEL key [key ...]
EXISTS key
KEYS pattern
TTL key
EXPIRE key seconds
PERSIST key
RANDOMKEY
FLUSHDB
FLUSHALL
RENAME oldkey newkey
TYPE key
```
### String Commands

```
SET key value
GET key
MSET key value [key value ...]
MGET key [key ...]
INCR key
DECR key
APPEND key value
```
### Hash Commands

```
HSET key field value
HGET key field
HMSET key field value [field value ...]
HMGET key field [field ...]
HDEL key field [field ...]
HGETALL key
```

### List 
```
LPUSH key value [value ...]
RPUSH key value [value ...]
LPOP key
RPOP key
LLEN key
LRANGE key start stop
```
### Set Commands
```
SADD key member [member ...]
SREM key member [member ...]
SMEMBERS key
SISMEMBER key member
```

### Configuration
```
CONFIG GET parameter
CONFIG SET parameter value
```

### Authentication
```
AUTH password
```