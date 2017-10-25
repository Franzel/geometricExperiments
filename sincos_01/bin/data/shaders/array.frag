#version 120

uniform float time;
uniform vec2 resolution;
uniform vec2 mouse;
uniform sampler2DRect tex;

float radius = 15.;

void main(){
    
    radius += sin(time)*5.;
    
    vec2 newMouse = mouse;
    newMouse = vec2(resolution.x, resolution.y)*0.5;
    newMouse.x += sin(time/3*(2+cos(time*0.3)*0.01))*300;
    newMouse.y += cos(time/3*3)*100;
    
    vec2 uv = gl_FragCoord.st / resolution;
    vec2 coord = gl_FragCoord.st - vec2(100);
//    vec3 color = texture2DRect(tex, gl_TexCoord[0].st).xyz;
    vec3 color = vec3(0,0,0);
    
    for (float i = -10.0; i<resolution.x+100; i += 30.0) {
        for (float j = -10.0; j<resolution.y+100; j += 30.0) {
            
            vec2 thisPoint = vec2(i,j);
            
            float dist = distance(thisPoint, gl_FragCoord.st );
            float mouseDist = distance(thisPoint, newMouse);
//            mouseDist *= 0.4;
            mouseDist = clamp(mouseDist,2,50);
            
            color.g  -= 0.0005*uv.x;
            color.r  -= 0.1/mouseDist*uv.y;
//            color += vec3(pow((radius-(mouseDist*0.15)) /dist ,2.)) ;
            color += vec3(pow(radius*2/mouseDist/dist*3, 1.5)) ;

        }
    }
    
    gl_FragColor = vec4(color,1.0);
}
