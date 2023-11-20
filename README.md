# cub3D

<div align="center">
  
```
______________________________/\\\____________/\\\\\\\\\\___/\\\\\\\\\\\\____        
 _____________________________\/\\\__________/\\\///////\\\_\/\\\////////\\\__       
  _____________________________\/\\\_________\///______/\\\__\/\\\______\//\\\_      
   _____/\\\\\\\\__/\\\____/\\\_\/\\\________________/\\\//___\/\\\_______\/\\\_     
    ___/\\\//////__\/\\\___\/\\\_\/\\\\\\\\\_________\////\\\__\/\\\_______\/\\\_    
     __/\\\_________\/\\\___\/\\\_\/\\\////\\\___________\//\\\_\/\\\_______\/\\\_   
      _\//\\\________\/\\\___\/\\\_\/\\\__\/\\\__/\\\______/\\\__\/\\\_______/\\\__  
       __\///\\\\\\\\_\//\\\\\\\\\__\/\\\\\\\\\__\///\\\\\\\\\/___\/\\\\\\\\\\\\/___ 
        ____\////////___\/////////___\/////////_____\/////////_____\////////////_____
```
  </div>
  
## Duo:
* Forabby / alde-fre ->	[Git](https://github.com/ForAbby-X) / [42.intra](https://profile.intra.42.fr/users/alde-fre)
* Wolran / vmuller ->	[Git](https://github.com/Wolran) / [42.intra](https://profile.intra.42.fr/users/vmuller)




### Description: 
Cub3D is a 3D horror RPG game designed using raycasting, within which we developed our own rasterizer to incorporate custom 3D models into the game.

## Screenshot:

![Screen1](https://github.com/Wolran/cub3D/blob/main/screenshots/close.png)
![Screen2](https://github.com/Wolran/cub3D/blob/main/screenshots/ennemy.png)
![Screen3](https://github.com/Wolran/cub3D/blob/main/screenshots/lose.png)
![Screen4](https://github.com/Wolran/cub3D/blob/main/screenshots/end.png)

## Basic project

- **3D Visualization:** Development of a 2D Game with 3D Visualization.
- **Map parser:** Incorporation of a map parser with specific conditions.
- **WASD keys:** Utilization of WASD keys for character movement and arrow keys for camera movement.
- **Textures:** Addition of textures to the walls.
- **Colors:** Assignment of colors to the floor and ceiling based on the map.
- **Exit the game:** The Escape key or the cross button should allow for closing the game.

## Features  

- **Custom Engine:** Integration of a custom engine in symbiosis with the minilibx.
- **Full 3D Graphics:** Game entirely in 3D, surpassing a simple 2D projection into 3D.
- **Camera Control:** Ability to control the camera using the mouse.
- **Advanced Textures:** Addition of reflection and transparency to textures.
- **Particles:** The particles are rendered as billboard images and collide with the walls.
- **Enemy AI:** Each enemy has their custom AI that interacts with the player.
- **Texture Modularity:** Ability to modulate textures on all walls, including the floor and ceiling, with colorization.
- **3D Rasterizer:** Creation of a 3D rasterizer to import .obj files.
- **3D Modeling on Blender:** Creation of custom 3D models for objects, enemies, and environments, including textures.
- **.obj File Parser:** Development of a custom parser for .obj files.
- **Procedural Generation:** Random generation of rooms, objects, and enemies.
- **In-Game Interface:** Presence of an in-game interface including health points, mini-map, FPS, settings, etc.
- **Animated Game Menu:** Addition of animations before and after the game in the game menu.
- **Inventory System:** Integration of an inventory system.
- **Advanced Collisions:** Addition of collisions between all entities, including entities with each other and the map, player, projectiles, etc.
- **Room Detection Algorithms:** Creation of an algorithm to detect rooms and strategically place objects and enemies.
- **Automatic Door Management:** Implementation of automatic door management during generation between rooms.
- **Constant Refresh Rate:** Maintaining a refresh rate between 40 and 90 frames per second.
- **Fog of War:** Integration of a fog of war with a shader.
- **Dynamic Change of Fog of War:** Modification of the color and range of the Fog of War in menus.
- **Easter egg:** It's up to you to find them.


## Run Locally :
#### Clone the project  
~~~bash
git clone https://github.com/Wolran/cub3D.git
~~~

#### Go to the project directory  
~~~bash  
cd cub3D
~~~

#### Make the project
~~~bash  
make fast
~~~

#### Starting the game 
~~~bash  
./cub3D "map"
~~~

*the test maps are in the map folder*

## Feedback  

If you have any feedback, please reach out to me at valentin@vmuller.fr.
