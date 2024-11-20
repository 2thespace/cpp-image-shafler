# cpp-image-shafler
put second image into first with pixel shuffle

# Build
'''
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
'''

# Example 

## Encode

Key word: hello_world

First image

![first_text](./example/first_image.png?raw=true)

Second Image

![second image](./example/second_image.png?raw=true)

```
./encoder ../example/first_image.png ../example/second_image.png hello_world ../example/encode_result.png

```

Result

![encode image](./example/encode_result.png?raw=true)

## Decode 

Key word: hello_world

Input

![encode image](./example/encode_result.png?raw=true)

```
./decoder ../example/encode_result.png hello_world ../example/decode_result.png
```

Result

![decode image](./example/decode_result.png?raw=true)
 
