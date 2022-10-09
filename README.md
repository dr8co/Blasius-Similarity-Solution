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

The momentum equation for a hydrodynamic boundary layer over a flat plate is given as:

$$u \dfrac {\partial u}{\partial x} + v \dfrac {\partial u}{\partial x} = \nu \dfrac {\partial ^2 u}{\partial y^2}$$

The velocity distribution in the boundary layer can be obtained by solving the equation above.
The following boundary conditions are satisfied:

* $(i)$ &emsp; At $y = 0, u = 0,$

* $(ii)$&emsp;At $y = 0, \nu = 0,$

* $(iii)$&emsp;At $y = \infty , u = U.$

The Blasius technique for an exact solution for the hydrodynamic layer lies in the conversion of momentum equation and the continuity equation:

$$\dfrac {\partial u}{\partial x} + \dfrac {\partial \nu}{\partial y}=0$$

As $u>\nu,$
$$\rho u\dfrac {\partial u}{\partial x}=\mu \dfrac {\partial ^2 u}{\partial y^2}$$
&emsp; &emsp; &emsp; since $\nu = \dfrac {\mu} {\rho}$.
