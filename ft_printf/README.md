# ft_printf: Imitate the behaviour of the original printf

#### The objective is not to imitate the whole function, only the main conversions. 
#### The conversions I had to do were char, string, hex, int, unsigned int, pointer and percentage.

<div style="text-align: right"> In this project, the main 'problem' was the management of structs, but when you to get used to this the project converts into a easy problem. For me was easier due to I knew Java so the concept is really similar to Java Objects but without object functions. </div>
<br>
<div style="text-align:right;font-weight:1"> These all files were created by me, Carlos Lostao </div>

### How to use

<div style="text-align:right;font-weight:1">For testing the project you only have to execute the following command:</div>
<br>
<br>
<code>make //This will generate a static library libftprintf.a</code>
<br>
<code>gcc libftprintf.a your_test_program.c</code>
