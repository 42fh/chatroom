# check that provided binary accepts client
PORT=$((8100 + $RANDOM % 1000))
$1 $PORT & #run server
nc 127.1 $PORT && echo OK || echo "Error couldn't reach server on port $PORT"
kill -s INT $!
