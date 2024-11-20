# cpp-image-shafler
put second image into first with pixel shuffle

# Example 

## Encode

Key word: hello_world

First image

![alt_text]()

Second Image

![alt_text](../first_image.png?raw=true)

```
./encoder ../example/first_image.png ../example/second_image.png hello_world ../example/encode_result.png

```

Result

![alt_text](../encode_result.png?raw=true)

## Decode 

Key word: hello_world

Input

![alt_text](../encode_result.png?raw=true)

```
./decoder ../example/encode_result.png hello_world ../example/decode_result.png
```

Result

![alt_text](../decode_result.png?raw=true)
 
