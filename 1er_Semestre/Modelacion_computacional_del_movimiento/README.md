## Modelacion computacional del movimiento
#
![alt text](https://github.com/SeaWar741/ITC/blob/master/1er_Semestre/Modelacion_computacional_del_movimiento/demo_image.PNG?raw=true)

### Challenge

The simulations that should be generated as final deliverables will give users the option to define the value of at least three variables to reflect their impact on the trajectory of the projectile. These variables are air resistance, initial velocity and angle of departure of the projectile, among others that may be included. It is of great value that they make the simulation with realistic values, with data that they have investigated regarding information on the possible size and mass of the possible ejected particles, possible air density at the time of the eruption, which is the velocity of the particle of output and the range of the ejection angle, and then its simulation not only shows the particle, but also shows as a result, in its conclusions presented to the design department, how high in meters the particles reach, how far in meters can to reach these particles, with what speed in meters per second it would be an impact blow to a rescuer.

When the simulation is executed, a screen must be displayed, where the movement of the projectile in two dimensions can be observed moment by moment, from its beginning and until the impact and that in a screen box the velocity values ​​are shown and updated and position of the object, the maximum height and point of impact of that projectile in meters, and also the speed just before the impact with the ground.

### Solution

The program receives the following inputs for 4 projectiles:
- Volcano height
- Mass
- Launch angle
- Initial velocity
- Coefficient of friction

Afterwards the program executes Euler formula to calculate the position from a given Δt

The program then calculates the max height, impact velocity and distance traveled in x axis
<p align="center">
<img src="https://github.com/SeaWar741/ITC/blob/master/1er_Semestre/Modelacion_computacional_del_movimiento/demo_image2.PNG?raw=true" width="300">
</p>
Then the data is exported as an Excel file and opened to be further examined by the user

### Compatibility
- MATLAB R2019a <br/>
- Excel functionality on Windows only

### Academic paper
[Download](Reporte_Reto.pdf)

### Team
- Abraham Cepeda Oseguera
- Alejandro Daniel González Carrillo
- Axel Giovanni Villanueva Cuéllar
- Hernan Salinas Ibarra
- Juan Carlos Garfias Tovar


### Download MATLAB App
[Download](Simulador_de_proyectiles_volcanicos/Simulador_de_proyectiles_volcanicos.mlappinstall)