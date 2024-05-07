# VRTestAutomationPlugin

The _VR Test Automation Plugin_ facilitates creating and running integration tests for VR systems with the [Daedalic Test Automation Plugin](https://github.com/DaedalicEntertainment/ue4-test-automation).

## Waypoints

Daedalic Test Automation Plugin is exposed to blueprints in order to allow easy test creation. The waypoint class can be created from the content browser. Adding a waypoint into a test level allows the test creator to setup the position of a VR pawn and controllers ready for the test.

Add a waypoint to the level.
Edit the position of the motion controllers to set the correct pose.
When running a test, call "Apply Waypoint to VR Pawn" to position the player during the test at the waypoint.

This method allows the test creator to have a simple method to control a player during the test runs.

Waypoints can also be reused as blueprints. This allows multiple tests needing the same pose to reuse the waypoint and updating the waypoint updates all tests.

### Adding The Plugin

1. Download the VRTestAutomation plugin.
1. Add plugin into unreal project `Plugins` folder.
1. Start the Unreal Editor.
1. Enable the plugin in Edit > Plugins.
1. Close the Unreal Editor.
1. Generate visual studio project files.
1. Build in Visual Studio.
1. Start the Unreal Editor.
 
"Oculus Rift" (https://skfb.ly/6nzBE) by Eternal Realm is licensed under Creative Commons Attribution (http://creativecommons.org/licenses/by/4.0/).

"Oculus touch" (https://skfb.ly/6ZBxs) by Lonk is licensed under Creative Commons Attribution-NoDerivs (http://creativecommons.org/licenses/by-nd/4.0/).