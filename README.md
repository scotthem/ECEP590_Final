# Johnny Five
## Introduction
This repo forms the submittal for the final project of ECEP 590 - Software Engineering for Embedded applications offered as part of the Professional Masters Program in Electrical Engineering at the University of Washington.

## Project Goals
This project will, using the robot state machine from the [week 8 homework](https://github.com/klavins/ECEP520/tree/master/week_7 "ECEP520 Week 8"), create a more realistic simulation of a security patrol robot.

This will be done using the [ELMA](http://klavinslab.org/elma/ "Elma Main Page") event loop and process manager that was developed during the ECEP 590 Winter class at the University of Washington and the code produced for the [week 8 homework](https://github.com/klavins/ECEP520/tree/master/week_7 "ECEP520 Week 8").

During this project I would like expand on the robot state machine adding more realism to the system.

I will create a simulation mode that implements a "simulated time" in order to speed up simulations and testing.

I will model the propulsion (motor) and power systems. This will including  changing in current requirements for different activities (evade , make noise should require more power for example) and a charging ciruit that mirrors a real battery charging cycle.

I will add a monitoring server and onboard client that will broadcast the status and location of the robot.

I will simulate the motion of the robot around its patrol patter and implement a method to change patrol paterns to random, to fixed patrol patterns as defined by the user.

A stretch goal for the maping, patrol routes and power systems implementation of this would be to add the effects of terain, and the addition of obstacles and intruders that would be detected when within a given distance. However, this may be beyond my abilities in the time allotted.

## Milestones

The following milestones will be used to report progress on the project, those not marked "**Stretch**" are considered to be the "complete" project.

[ ] Create directory structure, docker container for the project, complile using robot state machine example from [week 8 homework](https://github.com/klavins/ECEP520/tree/master/week_7 "ECEP520 Week 8").

[ ] Identify a suitable method for implementing a "simulated time" in order to reduce the overall simulation time during testing.

[ ] Simulate the on power systems including realistic battery loading based upon the activity and a charge cycle with a typical recharge curve.

[ ] Allow the patrol robot to report position and status to a remote server at regular intervals as well as during events of interest.

[ ] Create set patrol patterns that can be simulated.

[ ] Create a suitable document set for the code.

[ ] **Stretch** Extend robot and patrol code to react automatically to simulated obstacles and intruders.

[ ] **Stretch** Extend the patrol patterns and power systems to include different terrain.

[ ] **Stretch** Create a simulated user control panel that would allow, for instance, deactivation of alarms, cancelling of patrols, force battery charging, chage patrol route, etc...

[ ] **Huge Stretch** Implement GUI for the user control and status. (Lets face it I have no idea where to start with this so probably won't happen. But hey, a guy has to have aspirations)

## References
T.B.D.
