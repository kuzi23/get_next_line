# get_next_line
# 42 project
//this project is going to make a function called get_next_line which is going to print the next line after '\n'
Its made up by 3 functions which are connected tegether to provide its functionality
Here are the functions:
    1.ft_read_from_fd
    2._extract_line

1.*Ft_Read_from_fd*
-This helper function reads data from the file descriptor 'fd'into the provided buffer , up to the specified size size.
_It checks for the situation wher read is return -1 or 0 and return NULL
_it allocates memmory for the new string to which we are going to put the words from buffer up to bytes_read.
_Then it copies to the data  to the new string and null terminate the string

2.*ft_extract_line*
-