## Description

This may be a bug in vtk, you can produce the problem in the following steps:
- create 2 cube in the scene, each cube with a actor
- cube1's opacity = 1, cube2's opacity = 0.5 (or other value < 1)
- render

You can see, the MultiSample aliasing seems not work on cube2 which has opacity < 1.

![image](https://github.com/baker-Xie/vtk_msaa_bug/assets/30395561/17643fff-5653-463c-9c4f-859b2a970aef)


Meanwhile, if you have several polydata (for example 3), and Set color attribute to each
polydata, then append them into one polydata, then MSAA won't work on this large polydata.

## Environment
- VTK 9.3
- Windows10
