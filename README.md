<h1>CLib_v2 Library : a C static library</h1>

*This library is a set of very basic but usefull tools for C developping<br />
Its goal is to ease C development by simplifying repetitive or long tasks like memory gestion*

***How to use: ***
<ol>
    <li>
        Add `CLib_v2.h` and `CLib_v2.a` to your project's folder
    </li>
    <li>
        Link CLib_v2 to your project by including CLib_v2.h: `#include "CLib_v2.h"`
    </li>
    <li>
        Compile linking the library<br />
        `gcc file1.c [...] fileN.c CLib_v2.a -o yourExecutable` you may add option `-Wall`
    </li>
</ol>
