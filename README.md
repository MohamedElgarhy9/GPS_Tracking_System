# GPS-Tracking-System
In this project we will develop a GPS tracking system using TM4C123G LaunchPad, the  system should store the moved trajectory after power-on until a destination point is         reached and calculate the taken distance.

### There are 4 possible options for the definition of the destination point:
    1. Once the moved distance exceeds 100m, stop adding new points to the 
      trajectory and the last point added to the trajectory is the target destination.
    2. Stop adding new points when a push button is pressed, and the last point added 
      to the trajectory is the last destination.
    3. Predefine the destination point in your code and when the system reaches this 
      point, stop adding new points to the trajectory.

### Other functions required by the system:
    1. When the destination point is reached the build-in LED of the launchpad should 
      be turned on.
    2. Display the calculated distance on 3 7-segment displays. You can update the 7-
      segment display continuously or once the destination point is reached.
  
# Functional Requirements:
    1. After power-on, the system should configure the following interfaces:
        1. UART to interface with the GPS module
        2. Digital Output for built-in LED
        3. Digital Output for 7-segment displays
    2. The system should read GPS module data and wait until there is a GPS fix 
      (Check GPS module datasheet to check how can this be done).
    3. The first point read with GPS fix should be appended to the trajectory as the start 
      point.
    4. Your system needs to read the coordinates from the GPS module in a periodic 
      manner to get your trajectory. Software delay or Systick timer should be used to 
      control rate of execution of main function depending on the update rate of the 
      GPS module.
    5. After reaching the destination point, the system should stop appending new 
      points.
    6. The output will be translated as the following.
        1. Stage 1: The built-in LED will be turned on when the target destination is 
        reached or when you exceed 100 meters.
        2. Stage 2: The taken distance will be displayed on 3 digits 7 segments.
    7. The trajectory of the distance should satisfy the following criteria:
        1. The total distance between the start and the end point should be > 100 
          meters.
        2. The path from the start point to the end point should form a non-straight 
          line.
        3. You have the freedom to select any starting point on google maps.
        4. Your software should calculate the total taken distance, and you should 
          compare the calculated distance with the distance obtained from google 
          maps.
        5. You should ensure that there is no big difference/deviation (error margin 
          should be <= 5%) between your calculated distance and the one shown 
          by google maps.
    8. The scenario will be as the follows:
        1. The user will open google maps and start his program running on TivaC 
          at the same time.
        2. The user should walk holding the kit and the opened google maps and 
          walk till he/she exceeds the 100 meters. 
        3. The user should follow the path which is given in Figure1 and walk in nonstraight line.
        4. Once the user reaches the destination point (according to definition 
          chosen from the 3 possible choices stated before), the LED will be turned 
          on and the 7-segment displays should be updated with the calculated 
          distance if they are not updated continuously. 
  

