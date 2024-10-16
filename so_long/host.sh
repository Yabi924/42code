export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0
# export DISPLAY=localhost:0
echo $DISPLAY