#version 120

uniform sampler2DRect tex;
uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

uniform float radius = 400;
uniform float zoom = 10; // the lower the number, more zoom

void main(){
    
    vec2 myPos;
    
//    myPos = vec2(resolution/2); // fix to center
    myPos = mouse;//use mouse

    
//    myPos.x += sin(time) * 100;
//    myPos.y += cos(time) * 100;
    
//    myPos.y = resolution.y-mouse.y; //only if not using a texture, see OF code
    
    vec2 coord = gl_TexCoord[0].st; //get coordinates from texture
    float dist = distance(myPos, coord); //get distance from pos to coordinate
    vec2 uv = gl_FragCoord.xy / resolution.xy;

    
    float distX = gl_TexCoord[0].x - myPos.x;
    float distY = gl_TexCoord[0].y - myPos.y;

    
//    if (dist < radius) {
//        float newRad = dist * zoom * dist/radius;
//        coord.x = myPos.x + distX/dist * newRad;
//        coord.y = myPos.y + distY/dist * newRad;
//    }
    
    //EXPERIMENTAL
    float newRad = pow(radius/dist, zoom);
    coord.x = myPos.x + distX/dist * newRad;
    coord.y = myPos.y + distY/dist * newRad;
    

    vec4 color = texture2DRect(tex,coord); // get color from texture
//    color.r = texture2DRect(tex,coord + 10).r; //some color channel aberration
//    color.g = pow(100/dist, 1.5); //some glowBall
    
    gl_FragColor = vec4(color);

    

}