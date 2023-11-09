Here, you can use terminal to convert a lot of stuff
Download bc on the debian based systems (don't know whether available on other platforms)
Here by default ibase(inputbase and obase(outputbase) are set to 10 
For example to convert decimal to hexadecimal:
```
echo "obase=16; <value>" | bc
```          
To convert hexadecimal to decimal:
```
echo "ibase=16; <value>" | bc
```           
To convert decimal to binary:
```
echo "obase=2; <value>" | bc
```          
To convert binary to hexadecimal;
```
echo "obase=16; ibase=2; <value>" | bc
```          
