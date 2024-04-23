# Z3 User propagator
## 1. Compiling the sample program
```shell
$ cd user_propagator
$ make
$ ./n-queens
```
## 2. user propagation component
### 2.1. Fixed event handler `fixed`
The fixed event handler `fixed` is used to implement logic that needs to be handled when a variable is fixed (assigned a value).
### 2.2. Equivalent event processor `eq`
The equivalence event handler `eq` is used to implement the logic that needs to be handled when an equivalence variable is found.
### 2.3. Final event handler `final`
The final event handler `final` is used to implement the logic that needs to be handled when the solution is finished.
### 2.4. Create event handler `created`
The creation event handler `created` is used to implement the logic that needs to be handled when a variable is created.
### 2.5. Decision Event Processor `decide`
The decision event handler `decide` is used to implement the logic that needs to be handled when a variable decision is made.