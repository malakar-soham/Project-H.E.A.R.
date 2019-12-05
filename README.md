# **Project-H.E.A.R.**

## **(Here Extinguish And Rescue)**

### _An artificially intelligent, autonomous, consistently monitoring IoT system_

#### _By Soham Malakar and Swastik Malakar_

![Alt text](/Pics/Poster.jpg)

### Summary:
Presently, the number of fire accidents leading to loss of life and assets has been nerve breaking. The rapid spread of the fire coupled with inefficient notification system, hinders people in the densely populated areas to escape. Our research showed that most fires grew into disasters due to delayed/wrong communication.

The call of the hour is not a post-incident analysis but rather a prompt action at the occurrence of the incident through automated artificially engineered machine that would send instant alerts to all the emergency authorities reducing the communication time and speeding up rescue operations.

Fire reforms should be planned through simple, inexpensive ways for protecting our homes and lowering the losses drastically. Keeping this in mind we created H.E.A.R., handy, user-friendly, 24*7*365 vigil, affordable alert system.

The mobile application notifies the concerned authorities of the precise incident location, showing routes to reach the location in shortest time and distance. Rescue operations will start in no time with a nonverbal yet accurate communication.

### Circuit Diagram:

The circuit diagram for Project H.E.A.R. ver2 is as shown below:

![Alt text](/Pics/CDiag.jpg)

### Method/Redesign/Working :

- **Version 1:**
  -	Automatic and instant detection of fire/gas leak with H.E.A.R.
  -	Immediately alert sent to rescue authorities – Police, Hospital and Fire Station.
  -	Alarm rung to alert the people nearby.
  -	Speedy rescue operations ensue as there is no delay in intimating the authorities so that they can take charge at the earliest.

  _ver1 Summary:_
    - This prototype is sends alerts using cellular networks by the use of a sim card and a SIM900 GSM module to the respective phone numbers of the users as text messages with details about the fire location.

    The circuit for Project H.E.A.R. ver1 is as shown below:

    <p align="center">
      <src="![Alt text](/Pics/circuit.jpg)">
    </p>



-	**Version 2:**
  -	Automatic and instant detection of fire/gas leak with real-time data monitoring by H.E.A.R.
  -	Alert and location data are instantly updated to our dedicated servers.
  - H.E.A.R. android app updates data in real-time and gets refreshed from the server continuously.
  -	H.E.A.R. android app shows up fire affected sites in a defined radius.
  -	Navigation to site via the shortest and fastest route which is suggested by precise and intelligent algorithms.

   _ver2 Summary:_
    - This prototype sends alerts to the server over a Wi-Fi network by the ESP32 Wi-Fi chip, whenever there is a fire. The precise location is updated to the servers instantaneously with the neo 6m module. The H.E.A.R. android app updates data in real-time and gets refreshed from the server continuously. Whenever it senses fire around the H.E.A.R. android app user in a 5 km radius it shows up the markers at fire incidents locations. The user can select a marker location and navigate to it via the shortest and fastest route which is suggested by precise and intelligent algorithms.
