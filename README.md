Sunday 25/11/2018: 
+Please read the const variables in Game.h for fixing it appropriately

+Rules of vehicle and animal class: 

 -Chain of vehicles will be on the odd row and animals will be on the even row,starting index of row of people's position is 0
 
 -Vehicle moves from the right of the screen to the left
 
 -Animal moves from the left of the screen to the right 
 
 -Distance between vehicle and animal will be change with respect to the current level .It means that for a fixing screen ,distance will determine the number of 
 vehicle and animal in a row(distance=length of screen - currentlevel -5)//warning must be changed
 
Game.h:

 +New Function:getVehicleByDefault,getAnimalByDefault,IncLevel
 
 +Modifying Function:updatePosPeople,updatePosVehicle,updatePosAnimal
 
 +Data hiding in Object class must be considered again
 
??:

+Condition of collision between people and object?
