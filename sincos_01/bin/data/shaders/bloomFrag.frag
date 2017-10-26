uniform sampler2DRect tex;
uniform float time;
float amount = 300.;
uniform vec2 resolution;
uniform vec2 mouse;
uniform float move;

void main(void)
{
    vec2 st = gl_TexCoord[0].st;
    vec4 col = texture2DRect(tex, st); //get color
    float aspectRatio = resolution.y / resolution.x;
    
    //---AVERAGING
    float mouseXpct = resolution.x/mouse.x;
    float offset = 3.0 ;
    vec4 n = texture2DRect(tex, st + vec2(0.0,-offset) );
    vec4 s = texture2DRect(tex, st + vec2(0.0,offset) );
    vec4 e = texture2DRect(tex, st + vec2(offset,0.0) );
    vec4 w = texture2DRect(tex, st + vec2(-offset,0.0) );
    vec4 ne= texture2DRect(tex, st + vec2(offset,-offset) );
    vec4 nw = texture2DRect(tex, st + vec2(offset,offset) );
    vec4 se = texture2DRect(tex, st + vec2(offset,offset) );
    vec4 sw = texture2DRect(tex, st + vec2(-offset,offset) );
    vec4 me = texture2DRect(tex, st );
    
    float brightPassThreshold = 1.0 * mouse.y;
    vec3 luminanceVector = vec3(0.2125, 0.7154, 0.0721);
    float luminance =dot(luminanceVector, col.xyz);
    luminance = max(0.0, luminance - brightPassThreshold);
    col.xyz *= sign(luminance);
    
    col += (n+e+s+w+ne+nw+se+sw+me) / 5.0;
    col = mix( texture2DRect(tex, st), col, 0.9);
    
    gl_FragColor = vec4(col.rgb, 1.0);
    //    gl_FragColor = texture2DRect(tex, st) ;
}

