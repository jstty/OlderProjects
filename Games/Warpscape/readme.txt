Blake   - Warp path movement
Cameron - Ship, Enemy, Models, Testing
Joseph  - Everything else

Keys:
   Left Arrow - Move Left
   Right Arrow - Move Right
   "," - Fire
   "a" - Move Left
   "d" - Move Right
   "z" - Fire
   " " - Fire
   "p" - Pause
   
   F1  - Toggle Show FPS
   F2  - Toggle Fullscreen
   ESC - Exit
   "1" - Normal Speed
   "2" - Slow Speed
   "3" - Super Slow Speed
   "4" - Fast Speed
   
   "h" - Toggle HDR
   "7" - Low Glow
   "8" - Medium Glow
   "9" - High Glow
   "0" - Very High Glow
   
   "n" - End Level and move to next
   "r" - Restart game (aka, go to title)

Tech Used:
   c++    - programming language
   OpenGL - 3D render (need lib)
   GLUT   - window management (need lib)
   GLEW   - shaders (source included)

Platform Supported:
   Windows (tested on 7)
   Mac OSX (tested on 10.6)

Compile:
   Windows (VS.NET 2008)
      project/vs.net/WarpAttack.sln
   Mac OS X (Xcode 3.2)
      project/xcode/warpattack.xcodeproj 

Source:
   All code located in "source"

Notes:
   Lighting
      - Pointed in -z
   Star Field
      - each star is a line with 100% to 0% opacity
      - change of normal vector the farther the star is from the center
   Warp Path
      - Used Fog to give sense of depth
      - Lights up polygon to give sense of motion
         - change color and opacity
      - Number of polygon segments and separation variable
      - Path moves in certain threshold
   Zoom In/Out
      - Title Screen
         - Changed perspective
         - Move Model Away from Camera
      - Levels
         - Changed perspective
         - Move Model Towards Camera
   Ship
      - Follows first polygon
      - Has selection of current track
      - Rotated to match on any convex polygon
   Ship Bullet
      - Fills in square as it travels down the warp path
   Enemy
      - Moves up warp path starting at end
      - Changes z angle halfway through
   HDR
      - We wanted a CRT glow effect
         - Could use Textured Quads
         - Decided on HDR/Bloom effect
            - Looked examples but Philip Rideout (http://prideout.net/archive/bloom/)
      - Process
         - Load vertex(process each 3D point) and fragment(process each pixel) shaders
         - Create Shader programs with each having a vertex and fragment shader
            - HiPass
               - thresholds the pixels to a given number
            - Blur(ran for both horizontal and vertical)
               - blurs pixel to surrounding per pixels
            - Combine
               - combine the colors from the source and blurred textures
         - Create Scene, and 2 Temporary offscreen buffers
            - FBO          (frame buffer object) contains the colors
            - RenderBuffer (depth buffer) contains depth values
            - Create Texture map
            - Bind RenderBuffer to FBO
            - Bind Texture map to FBO
         - Bind Scene and Draw game as normal
         - HiPass
            - Select HiPass Shader program
            - Select Scene texture
            - Select Temp1 FBO
            - Draw Quad with texture
               - the texture will be processed with the HiPass shader and drawn to Temp1 texture
         - Blur Horizontal
            - Select Blur Shader program
            - Select Temp1 texture
            - Select Temp2 FBO
            - Draw Quad with texture
               - the texture will be processed with the Blur shader and drawn to Temp2 texture
         - Blur Vertical
            - Select Blur Shader program
            - Select Temp2 texture
            - Select Temp1 FBO
            - Draw Quad with texture
               - the texture will be processed with the Blur shader and drawn to Temp1 texture
         - Combine
            - Select Combine Shader program
            - Select Temp1 texture
            - Select Screen FBO(Zero)
            - Draw Quad with texture
               - needed to account do the screen size not being a power of 2 and square
               - the texture will be processed with the Combine shader and drawn to Screen
   Loaded from file
      - All polygons, models and animations
      - All vertex and fragment shaders
   Misc Features
      - Pause
      - Slow down or Speed up the game
   Future Improvements
      - Make enemy rotate from track to track
      - More types of enemies
      - More levels
      - ALL settings loaded from files
      - Levels of difficulty
      - Settings screen
      ...
