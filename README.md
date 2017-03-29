# Anaglyph3DGen

## Introduction

Anaglyph is a simple Qt application to generate anaglyph 3D image.

Ths program takes 3 input : Image for left eye, image for right eye, and an offset.

The program will convert both images to greyscale image, in a simple way : (Red + Green + Blue) / 3. Which might be inaccurate.
Then it assign the grey scale to red / blue channel of left / right part of the image, generating the final result.

The distance between the left and the right part of the image is the offset specified by user

## Example

Here's an example of this application ( Offset = 20px )

Image for left eye: 

![Image for left eye](https://github.com/tansinan/Anaglyph3DGen/blob/master/Example/Picture_Left.png)

Image for right eye: 

![Image for left eye](https://github.com/tansinan/Anaglyph3DGen/blob/master/Example/Picture_Right.png)

Result: 

![Result](https://github.com/tansinan/Anaglyph3DGen/blob/master/Example/Result.bmp)
