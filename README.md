## CCAT

Custom cat tool, with basic functionality.

## Setup

Clone repository and run `make`. Will compile and test the code. 
To run you will need to use `<path_to_ccat>/ccat`. If you wish to call it using just `ccat`, move the compiled binary into `/usr/local/bin` using 
```
sudo mv ccat /usr/local/bin/
```

Supported Arguments:

| Arg | Function |
|:---:|:-------- |
| - | read from stdin |
| -n | Numbers the lines |
| -b | Number non empty lines |