#version 120

uniform float time;
uniform vec2 resolution;
uniform vec2 mouse;
uniform sampler2DRect tex;

float radius = 15.;

void main(){
    
    radius += sin(time*500)*5.;
    
        vec2 newMouse = mouse;
    ////    //comment following 3 lines to use mouse
    //    newMouse = vec2(resolution.x, resolution.y)*0.5;
    //    newMouse.x += sin(time/3*(2+cos(time*0.3)*0.01))*300;
    //    newMouse.y += cos(time/3*3)*100;
    
    vec2 uv = gl_FragCoord.st / resolution;
    vec2 coord = gl_FragCoord.st - vec2(500);
    vec3 color = texture2DRect(tex, gl_TexCoord[0].st).xyz;
    //    vec3 color = vec3(0,0,0);
    
    
I
    //    float distX = gl_TexCoord[0].x;
    //    float distY = gl_TexCoord[0].y;
    //    vec2 distXY = vec2(distX,distY);
//    float dist = distance(coord, gl_FragCoord.st);
    //        float dist = distance(mouse,gl_FragCoord.st); // get distance
    //
    //    dist /= 1.0 + cos(time*10)*0.03; // change scale of distance
    //
    color.rgb = vec3(pow(dist*0.1, 0.11)); // make gradient using dist
    //    color.g = pow(2.0/dist, 1.0);
    
    //-- all the rest of fancy pixel operations
    //    color.b =  mix(color.r, 2.5, cos(time)*0.5) * 0.4;
    //    color.r = smoothstep(color.b, color.g, color.b);
    //    color.r += smoothstep(0,1,1*(sin(time)*0.5));
    //    color += vec3(mod(time,0.06));
    //    color.r += (sin(gl_FragCoord.y * (sin(10)*20.0)) + 1.0) * 0.2;
    
    gl_FragColor = vec4(color,1.0);
}
