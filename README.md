str_struct
==========

A simple C-based string management framework that is fully compatible with char*.

To Use
------

1. Add the `str_struct.h` and `str_struct.c` files to your project. 
2. Include `str_struct.h` into your code. 
3. Use it with 

```C
Str *myStr = Str_new();
myStr->set("my new string");
myStr->set("%d %s", 626, "i like this string better");
```

or

`Str *myStr = Str_newWith("hello world");`

or 

`Str *myStr = Str_newWith("the speed is %2.3f km/h", 24.56789);`

4. Print it with printf

`printf("the string is %s, with %d characters, including null terminator.\n", myStr->str, myStr->length);`

5. Free it after use. 

`Str_dispose(myStr);`



Included here is `str_driver.c` where it will test all the convenience functions. 

Use that as your guide for the available functions included. 

To Compile str_driver.c
-----------------------

```script
gcc -o str_driver str_driver.c str_struct.c
```

To Test
-------
```script
./str_driver
```
You should see a list of string related tests printed.


Known Issues
------------
1. The `replace()` function is yet to be implemented. 


