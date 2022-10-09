# A Numerical Solution to the Blasius Boundary Layer Equation

## Overview

This solution considers the Similarity Solution for a
[Blasius Boundary Layer](https://en.wikipedia.org/wiki/Blasius_boundary_layer)
for a flow over a flat plate of length unity.\
The similarity variables are given by:

$$
\begin{align}
    \eta ={\dfrac {y}{\delta (x)}}=y{\sqrt {\dfrac {U}{\nu x}}},\\
    \\
    \psi ={\sqrt {U \nu x}}f(\eta )\\
    \\
    f'(\eta) = {\dfrac {u}{U}},\\
    \\
\end{align}
$$

&emsp; &emsp; &emsp; Where:\
$\quad \quad \quad \quad \delta (x)$ is the boundary layer thickness,\
$\quad \quad \quad \quad \psi$ is the stream function, and\
$\quad \quad \quad \quad U$ denotes the freestream velocity, and $u$ the local velocity.

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

$$u \dfrac {\partial u}{\partial x} + v \dfrac {\partial u}{\partial x} =
\nu \dfrac {\partial ^2 u}{\partial y^2} \tag{1}$$

The velocity distribution in the boundary layer can be obtained by solving the equation above.
The following boundary conditions are satisfied:

* $(i)$ &emsp; At $y = 0, u = 0,$

* $(ii)$&emsp;At $y = 0, \nu = 0,$

* $(iii)$&emsp;At $y = \infty , u = U.$

The Blasius technique for an exact solution for the hydrodynamic layer
lies in the conversion of momentum equation and the continuity equation:

$$\dfrac {\partial u}{\partial x} + \dfrac {\partial \nu}{\partial y}=0 \tag{2}$$

As $u\ge \nu,$
$$\rho u\dfrac {\partial u}{\partial x}=\mu \dfrac {\partial ^2 u}{\partial y^2}$$
&emsp; &emsp; &emsp; since $\nu = \dfrac {\mu} {\rho}$.

Also, as $u \propto U$ and $\dfrac {\partial u}{\partial x} \propto \dfrac {U}{L},$
along a plate length $L,$ therefore,

$$\dfrac {\rho U^2}{L} = \mu \dfrac {U}{\delta ^2}$$
$$\therefore \delta = \sqrt {\dfrac {\mu L}{\rho U}} =
\sqrt {\dfrac {\nu L}{U}} = \sqrt {\dfrac {\nu x}{U}} \tag{3}$$

The dimensionless velocity $\dfrac{u}{U}$ can be expressed at any location Sx$
as a function of the dimensionless distance from the wall $\dfrac {y}{\delta}$.

$$\dfrac {u}{U}=f \biggl(\dfrac {y}{\delta} \biggr) \tag{4}$$

Substituting the value of $\delta$ from eqn. $(3)$ in eqn. $(4)$, we obtain,

$$\dfrac {u}{U}=f\biggl[\dfrac {y}{\sqrt {x}} \sqrt {\dfrac {U}{\nu}}\biggr]
= f(\eta) \tag{5}$$

Where, $\quad \eta = y \sqrt {\dfrac {U}{\nu x}} $

The stream function, $\psi$ can be defined such that,

$$\dfrac {\psi}{U} = \biggl [\sqrt {\dfrac {\nu x}{U}} \biggr] f(\eta) \tag{6}$$

Or,

$$\psi = \sqrt {\nu x U} f(\eta) \tag{7}$$

The partial differential of the stream function with respect to $x$
gives the velocity in the $Y$-direction (generally taken as negative)
and its partial differential with respect $y$ gives the velocity
in the $X$-direction:

$$u = \dfrac {\partial \psi}{\partial y}; \quad \quad
v = \dfrac {\partial \psi}{\partial x}$$

$$
\therefore \dfrac {\partial \psi}{\partial y} = \dfrac {\partial \psi}{\partial \eta}
\times \dfrac {\partial \eta}{\partial y} = \dfrac {\partial}{\partial \eta}
\biggl[U\sqrt{\dfrac {\nu x}{U}}f(\eta) \biggr] \times
\dfrac {\partial}{\partial y} \biggl[y \sqrt{\dfrac {U}{\nu x}} \biggr]
$$

Or,

$$
u=U\sqrt {\dfrac {\nu x}{U}} \dfrac {df}{d\eta}\biggl [\sqrt {\dfrac {U}{\nu x}} \biggr]
= U\dfrac {df}{d\eta} \tag {8}
$$

Here $f$ is abbreviated as $f(\eta)$

$$
\therefore \dfrac {\partial u}{\partial x} = U\dfrac {\partial}{\partial x}
\left [\dfrac {df}{d\eta} \right] = U\dfrac {\partial}{\partial \eta}
\left [\dfrac {df}{d\eta} \right] \dfrac {\partial}{\partial x}
=-U\dfrac{d^2 f}{d \eta ^2} \cdot \dfrac {1}{2 x} \cdot y \sqrt{\dfrac {U}{\nu x}}
$$

Or,

$$
\dfrac {\partial u}{\partial x} = -U \dfrac {\eta}{2x} \dfrac {d^2 f}{d\eta ^2} \tag{9}
$$
