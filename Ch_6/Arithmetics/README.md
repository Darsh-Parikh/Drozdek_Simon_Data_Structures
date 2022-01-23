Write a program to perform the four basic arithmetic operations, +, -, * and /,
on very large integers (the result of division should also be an integer). 
Apply these to compute (123 ^ 45) or 1 * 2 + 3, 2 * 3^2 + 4, 3 * 4^3 + 5, ...
Also, apply them to compute the Godel numbers of arithmetical expressions.
    
    The Godel numbering function GN first establishes a correspondence between 
basic elements of language and numbers:
            SYMBOL              |           Godel Number GN
                =                               1
                +                               2
                *                               3
                -                               4
                /                               5
                <                               6
                >                               7
                ^                               8
                0                               9
                S                               10
                x_i                             11 + (2 * i)
                X_i                             12 + (2 * i)

where S is the successor function. Then, for any F = s_1 * s_2 *... * s_n:
        GN(F) = 2^(GN(s_1)) * 3^(GN(s_2)) * ... p_n^(GN(s_n)),
where p_n is the nth prime. For example,
        GN(1) = GN(S0) = 2^10 * 3^9
and
        GN('x_1 + x_3 = x_4') = 2^(11+2) * 3^(2) * 5^(11+6) * 7^(1) * 11^(11+8)

In this way, every arithmetical expression can be assignemd a unique number. 
This method has benn used by Godel to prove the Godel theorems.