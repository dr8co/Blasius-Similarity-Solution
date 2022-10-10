# A Numerical Solution to the Blasius Boundary Layer Equation

## Table of Content

* [Overview](#overview)
* [Derivation](#derivation)
* [This solution](#this-solution)

_________________________________________________________

## Overview

A Blasius boundary layer (named after [Paul Richard Heinrich Blasius](https://en.wikipedia.org/wiki/Paul_Richard_Heinrich_Blasius))
describes the steady two-dimensional laminar boundary layer that forms on a semi-infinite plate
which is held parallel to a constant unidirectional flow.

Blasius obtained an exact solution for the
[Boundary Layer Equations](https://en.wikipedia.org/wiki/Boundary_layer#Boundary_layer_equations)
by assuming a zero pressure gradient.

[This numerical solution](#this-solution) considers the [Blasius Exact Solution](https://en.wikipedia.org/wiki/Blasius_boundary_layer)
for laminar boundary layer flow over a flat plate.\
The similarity variables are given as:

$$
\begin{align*}
    & \eta ={\dfrac {y}{\delta (x)}}=y{\sqrt {\dfrac {U}{\nu x}}},\\
    \\
    & \psi ={\sqrt {U \nu x}}f(\eta )\\
\end{align*}
$$

&emsp; &emsp; &emsp; Where:\
$\quad \quad \quad \quad \delta (x)$ is the boundary layer thickness,\
$\quad \quad \quad \quad \psi$ is the stream function, and\
$\quad \quad \quad \quad U$ denotes the freestream velocity, and $u$ the local velocity.

The Blasius similarity equation is given by:
$$ff'' + 2f''' = 0$$
The Boundary conditions are given as:

$$
\begin{align*}
    & f(0) = 0,\\
    \\
    & f'(0) = 0,\\
    \\
    & f'(\infty) = 1.
\end{align*}
$$

_________________________________________________________

## Derivation

The momentum equation for a hydrodynamic boundary layer over a flat plate is given as:

$$
u \dfrac {\partial u}{\partial x} + v \dfrac {\partial u}{\partial x} =
\nu \dfrac {\partial ^2 u}{\partial y^2} \tag{1}
$$

The velocity distribution in the boundary layer can be obtained by solving the equation above.
The following boundary conditions are satisfied:

* $(i)$ &emsp; At $y = 0, \quad u = 0,$

* $(ii)$&emsp;At $y = 0, \quad \nu = 0,$

* $(iii)$&emsp;At $y = \infty , \quad u = U.$

The Blasius technique for an exact solution for the hydrodynamic layer
lies in the conversion of momentum equation and the continuity equation:

$$\dfrac {\partial u}{\partial x} + \dfrac {\partial v}{\partial y}=0 \tag{2}$$

As $u\ge v,$

$$
\rho u\dfrac {\partial u}{\partial x}=\mu \dfrac {\partial ^2 u}{\partial y^2}
$$

&emsp; &emsp; &emsp; since $\nu = \dfrac {\mu} {\rho}$.

Also, as $u \propto U$ and $\dfrac {\partial u}{\partial x} \propto \dfrac {U}{L},$
along a plate length $L,$ therefore,

$$\dfrac {\rho U^2}{L} = \mu \dfrac {U}{\delta ^2}$$

$$
\therefore \delta = \sqrt {\dfrac {\mu L}{\rho U}} =
\sqrt {\dfrac {\nu L}{U}} = \sqrt {\dfrac {\nu x}{U}} \tag{3}
$$

The dimensionless velocity $\dfrac{u}{U}$ can be expressed at any location $x$
as a function of the dimensionless distance from the wall $\dfrac {y}{\delta}$.

$$\dfrac {u}{U}=f \Biggl(\dfrac {y}{\delta} \Biggr) \tag{4}$$

Substituting the value of $\delta$ from eqn. $(3)$ in eqn. $(4)$, we obtain,

$$
\dfrac {u}{U}=f\Biggl[\dfrac {y}{\sqrt {x}} \sqrt {\dfrac {U}{\nu}}\Biggr]
= f(\eta) \tag{5}
$$

Where, $\quad \eta = y \sqrt {\dfrac {U}{\nu x}}$ denotes the stretching factor

The stream function, $\psi$, can be defined such that,

$$\dfrac {\psi}{U} = \Biggl [\sqrt {\dfrac {\nu x}{U}} \Biggr] f(\eta) \tag{6}$$

Or,

$$\psi = \sqrt {\nu x U} f(\eta) \tag{7}$$

The partial differential of the stream function with respect to $x$
gives the velocity in the $Y$-direction (generally **taken as negative**)
and its partial differential with respect $y$ gives the velocity
in the $X$-direction:

$$
u = \dfrac {\partial \psi}{\partial y}; \quad \quad
v = \dfrac {\partial \psi}{\partial x}
$$

$$
\therefore \dfrac {\partial \psi}{\partial y} = \dfrac {\partial \psi}{\partial \eta}
\times \dfrac {\partial \eta}{\partial y} = \dfrac {\partial}{\partial \eta}
\Biggl[U\sqrt{\dfrac {\nu x}{U}}f(\eta) \Biggr] \times
\dfrac {\partial}{\partial y} \Biggl[y \sqrt{\dfrac {U}{\nu x}} \Biggr]
$$

Or,

$$
u=U\sqrt {\dfrac {\nu x}{U}} \dfrac {df}{d\eta}\Biggl [\sqrt {\dfrac {U}{\nu x}} \Biggr]
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

Now,

$$
\dfrac {\partial u}{\partial y}={U}{\dfrac {\partial}{\partial y}}\Biggl (\dfrac {df}{d\eta}\Biggr)
={U}{\dfrac {\partial}{\partial \eta}}\Biggl(\dfrac {\partial f}{\partial \eta}\Biggr)
\dfrac {\partial \eta}{\partial y} \cdot {U}{\sqrt {\dfrac {U}{\nu x}}}
\cdot \dfrac {d^2 f}{d\eta ^2} \tag{10}
$$

Similarly,

$$
\dfrac {\partial ^2 u}{\partial y^2} = \dfrac {U^2}{\nu x}
\cdot \dfrac {d^3 f}{d\eta ^3} \tag{11}
$$

Again,

$$
\begin{align*}
& v = - \dfrac {\partial \psi}{\partial x} = - \dfrac {\partial}{\partial x}
\Biggl [\sqrt {\dfrac {\nu x}{U}}f(\eta) \Biggr] = -U\sqrt {\dfrac {\nu}{U}}
\cdot \dfrac {\partial}{\partial x}[\sqrt {x}f(\eta)] \\
\\
& =-U\sqrt {\dfrac {\nu}{U}} \cdot \Biggl[\sqrt {x}\dfrac {\partial f}{\partial x} +
f \cdot \dfrac {\partial}{\partial x}(\sqrt {x})\Biggr]\\
\\
& =-U\sqrt {\dfrac {\nu}{U}} \cdot \Biggl[\sqrt {x}\dfrac {\partial f}{\partial \eta}
\cdot \dfrac {\partial \eta}{\partial x} + \dfrac {f}{2\sqrt{x}}\Biggr] \\
\\
& =-U\sqrt {\dfrac {\nu}{U}} \cdot \Biggl[\sqrt {x}\dfrac {\partial f}{\partial \eta}
\cdot \dfrac {\partial}{\partial x} \Biggl(y\sqrt {\dfrac {U}{\nu x}}\Biggr) +
\dfrac {f}{2\sqrt {x}} \Biggr] \\
\\
& =-U\sqrt {\dfrac {\nu}{U}} \cdot \Biggl[\sqrt {x}\dfrac {\partial f}{\partial \eta}
\cdot y\sqrt {\dfrac {U}{\nu}} \Biggl(-\dfrac {1}{2} \Biggr) \dfrac {1}{x\sqrt {x}} +
\dfrac {f}{2\sqrt {f}} \Biggr] \\
\\
& =-\sqrt {U\nu} \dfrac {1}{2\sqrt {x}} \Biggl[-\dfrac {df}{d\eta}y
\sqrt {\dfrac {U}{\nu x}} + f \Biggr] \\
\\
& =-\dfrac {1}{2} \sqrt {\dfrac {Ux}{x}} \Biggl[-\eta \dfrac {df}{d\eta} + f \Biggr] \\
\\
\end{align*}
$$

$$
\begin{align}
& v = \dfrac {1}{2} \sqrt {\dfrac {U\nu}{x}} \Biggl[ -\eta \dfrac {df}{d\eta} -f \Biggr] \tag{12}
\end{align}
$$

Inserting the values of $u, \dfrac {\partial u}{\partial x}, \dfrac {\partial u}{\partial y}$,
$\dfrac {\partial ^2 u}{\partial x^2}$ and $v$ from eqns. $(8), (9),$
$(10),$ and $(11)$ in eqn $(1)$, we get

$$
-U\dfrac {df}{d\eta} \cdot U \dfrac {\eta}{zx} \cdot \dfrac {d^2 f}{d\eta ^2} +
\dfrac {1}{2} \sqrt {\dfrac {U\nu}{x}} \Biggl[\eta \dfrac {df}{d\eta} -f \Biggr]
\cdot U\sqrt {\dfrac {U}{\nu x}} \dfrac {d^2 f}{d\eta ^2} = \nu \dfrac {U^2}{\nu x}
\cdot \dfrac {d^3 f}{d \eta ^3}
$$

Or,

$$
-\dfrac {1}{2x} \cdot U^2 \dfrac {df}{d\eta} \cdot \eta \dfrac {d^2 f}{d\eta ^2} +
\dfrac {1}{2x}U^2 \dfrac {d^2 f}{d\eta ^2} \Biggl[\eta \dfrac {df}{d\eta} - f \Biggr]
=\dfrac {U^2}{x} \cdot \dfrac {d^3 f}{d\eta ^3}
$$

Or,

$$
-\dfrac {1}{2x} U^2 \dfrac {d^2 f}{d\eta ^2} \Biggl[\eta \dfrac {df}{d\eta}-
\eta \dfrac {df}{d\eta} + f \Biggr] = \dfrac {U^2}{x} \cdot \dfrac {d^3 f}{d\eta ^3}
$$

Or,

$$
-\dfrac {1}{2x}U^2 \dfrac {d^2 f}{d\eta ^2} \cdot f = \dfrac {U^2}{x}
\cdot \dfrac {d^3 f}{d\eta ^3}
$$

Or,

$$
2 \dfrac {d^3 f}{d\eta ^3} + f \dfrac {d^2 f}{d\eta ^2} = 0
$$

Or,

$$
2f''' + f'' = 0 \tag{13} \\
$$

The physical and transformed boundary conditions are:

| Physical boundary conditions | Transformed boundary conditions                      |
|------------------------------|------------------------------------------------------|
| at $y = 0, \quad u = 0$      | at $\eta = 0, \quad \dfrac {df}{d\eta} = f'= 0$      |
| at $y = 0, \quad v = 0$      | at $\eta = 0, \quad f = 0$                           |
| at $y = \infty, \quad u = U$ | at $\eta = \infty, \quad \dfrac {df}{d\eta} = f'= 1$ |

_________________________________________________________

## This Solution
