uniform sampler2DRect tex;
uniform float time;
float amount = 300.;
uniform vec2 resolution;
uniform vec2 mouse;
float move;


const vec4 color = vec4(0.527, 0.250, 0.137, 1.0);

void main(void)
{
    float aspectRatio = resolution.y / resolution.x;
    vec2 st = gl_TexCoord[0].st;
    
    
    vec2 screenSpaceCoord = vec2((gl_FragCoord.x  / resolution.x  - 0.5) , (gl_FragCoord.y / resolution.y  - 0.5) * aspectRatio ) * 2.0;

    
    
    
    float brightPassThreshold = 0.5;
    vec3 luminanceVector = vec3(0.2125, 0.7154, 0.0721);
    
    vec4 col = texture2DRect(tex, st); //get color
    float luminance =dot(luminanceVector, col.xyz);
    luminance = max(0.0, luminance - brightPassThreshold);
    col.xyz *= sign(luminance);
    col.x += float(mouse.x);
    col.y *= float(mouse.y);
//    col.xyz /= vec3(mouse.x, 1.0, 0.5);
    
//    col.xyz -= vec3(mouse.x, 0,0);
    
    
    gl_FragColor = vec4(col.xyz, 1.0);
}





//void main(){
//    vec4 vertColor;
//    vec4 vertTexCoord;
//    float brightPassThreshold = 0.5;
//    vec3 luminanceVector = vec3(0.2125, 0.7154, 0.0721);
//
//    vec4 c = texture2DRect(tex, gl_Texcord[0].st);
//
//    float luminance = dot(luminanceVector, c.xyz);
//    luminance = max(0.0, luminance - brightPassThreshold);
//    c.xyz *= sign(luminance);
//    c.a = 1.0;
//
//gl_FragColor = c;
//
//}

