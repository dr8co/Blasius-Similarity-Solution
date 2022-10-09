# A Numerical Solution to the Blasius Boundary Layer Equation

## Overview

This solution considers the Similarity Solution for a [Blasius Boundary Layer](https://en.wikipedia.org/wiki/Blasius_boundary_layer)
for a flow over a flat plate of length unity.\
The similarity variables are given by:

$$
\begin{align}
    \eta ={\dfrac {y}{\delta (x)}}=y{\sqrt {\dfrac {U}{\nu x}}},\\
    \\
    \quad \psi ={\sqrt {U \nu x}}f(\eta )\\
    \\
    f'(\eta) = {\dfrac {u}{U}},\\
    \\
\end{align}
$$

&emsp; &emsp; &emsp; Where:\
&emsp; &emsp; &emsp; &emsp; $\delta (x)$ is the boundary layer thickness,\
&emsp; &emsp; &emsp; &emsp; $\psi$ is the stream function, and\
&emsp; &emsp; &emsp; &emsp; $U$ denotes the freestream velocity, and $u$ the local velocity.

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

## Derivation
