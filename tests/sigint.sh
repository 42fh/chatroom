# gets executable as arg
$1 &
sleep 0.1
kill -s INT $! && echo OK || echo "Error PID $! not running"
