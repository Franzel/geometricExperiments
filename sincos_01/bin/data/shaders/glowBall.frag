#version 120

uniform vec2 mouse;
uniform vec2 resolution;
uniform float time;


void main(){
    vec2 mouse = mouse; // uncomment this to use mouse
    mouse.y = resolution.y - mouse.y; //invert Y
    
    vec3 color = vec3(0,0,0);        // make everything black
    
    
    float distX = mouse.x;
    float distY = mouse.y;
    vec2 distXY = vec2(distX + sin(time)*100, distY - smoothstep(-200,200,cos(time)*200)*300);
    float dist = distance(distXY, gl_FragCoord.st);
//    float dist = distance(mouse,gl_FragCoord.st); // get distance
    
    dist /= 1.0 + cos(time*10)*0.03; // change scale of distance
    
    color.rgb = vec3(pow(20/dist, 1.2)); // make gradient using dist
    color.g = pow(100/dist, 1.5);
    
    //-- all the rest of fancy pixel operations
    color.b =  mix(color.r, 2.5, cos(time)*0.5) * 0.4;
    
    color.r = smoothstep(color.b, color.g, color.b);
    
    
    color.r += smoothstep(0,1,1*(sin(time)*0.5));
    color += vec3(mod(time,0.06));
    color.r += (sin(gl_FragCoord.y * (sin(10)*20.0)) + 1.0) * 0.2;

    gl_FragColor = vec4(color,1.0); // output color
    
}