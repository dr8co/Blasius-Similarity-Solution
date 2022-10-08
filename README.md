# A Numerical Solution to the Blasius Boundary Layer Equation

This solution considers the Similarity Solution for a [Blasius Boundary Layer](https://en.wikipedia.org/wiki/Blasius_boundary_layer)
for a flow over a flat plate of length unity.\
The similarity variables are given by:

$$
\begin{align}
    \eta = y \sqrt{U\over x\nu},\\
    \\
    f'(\eta) = {u\over U},\\
    \\
    {1/2}\sqrt{U\nu\over x}{(nf' - f)}
\end{align}
$$

$U$ denotes the freestream velocity.
The Blasius similarity equation is given by:
$$ff'' + 2f''' = 0$$
The Boundary conditions are given as:

$$
\begin{align}
    f(0) = 0,\\
    \\
    f'(0) = 0,\\
    \\
    f'(\infty) = 1
\end{align}
$$
