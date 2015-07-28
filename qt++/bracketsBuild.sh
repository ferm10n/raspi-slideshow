#!/bin/bash
PROJECT_NAME=$(pwd | grep -Eo '/[^/]*?$')
make
if [ $? -eq 0 ]; then
    .$PROJECT_NAME
fi
