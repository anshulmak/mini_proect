# mini_proect
# To design a robot which can navigate in a maze.
We need ultrasonic sensors in robot to measure the distance to an object by using sound waves. It measures distance by sending out a sound wave at a specific frequency and listening for that sound wave to bounce back. We can check the obstacle and move the robot accordingly.
In case of Terrain with low visibility, we can use infrared sensors which are used to sense certain characteristics of its surroundings by either emitting and/or detecting infrared radiation.These sensors can detect the obstacle in a dark area and move the robot accordingly.
For the navigation of robot in maze , I have used backtracking technique.
#Algorithm
If destination is reached
    print the solution matrix
Else
   a) Note the current location of robot. 
   b) Move forward in horizontal direction and recursively check if this 
       move leads to a solution. 
   c) If the move chosen in the above step doesn't lead to a solution
       then move down and check if  this move leads to a solution.
    c) If the move chosen in the above step doesn't lead to a solution
       then move backward and check if  this move leads to a solution.
      c) If the move chosen in the above step doesn't lead to a solution
       then move up and check if  this move leads to a solution.
   d) If none of the above solutions work then unmark the location
       (BACKTRACK) and return false.
       
