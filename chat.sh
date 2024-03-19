#!/bin/bash

i=0
count=0

# Function to generate argument from Python script
generate_arg() {
    python3 script.py
}

# Repeat until count is above 5500
while [ $count -le 5500 ]; do
    arg=$(generate_arg)
    count=$(echo "$arg" | ./push_swap $arg | wc -l)
    echo $count
done

# Output the argument and count
echo "Argument: $arg"
echo "Line count: $count"
