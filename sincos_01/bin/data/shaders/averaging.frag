//this shader performs averaging, creating a blur effect
//grabs the pixels around the current one and averages them

uniform sampler2DRect tex;
uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

void main(){

	vec2 st = gl_TexCoord[0].st;
	vec4 color= texture2DRect(tex, st);

    float mouseXpct = resolution.x/mouse.x;
	float offset = 100.0 * mouseXpct;
    
    

  vec4 n = texture2DRect(tex, st + vec2(0.0,-offset) );
  vec4 s = texture2DRect(tex, st + vec2(0.0,offset) );
  vec4 e = texture2DRect(tex, st + vec2(offset,0.0) );
  vec4 w = texture2DRect(tex, st + vec2(-offset,0.0) );
  vec4 ne= texture2DRect(tex, st + vec2(offset,-offset) );
  vec4 nw = texture2DRect(tex, st + vec2(offset,offset) );
  vec4 se = texture2DRect(tex, st + vec2(offset,offset) );
  vec4 sw = texture2DRect(tex, st + vec2(-offset,offset) );
  vec4 me = texture2DRect(tex, st );
	
     gl_FragColor = vec4(color) + (n+e+s+w+ne+nw+se+sw+me) / 9.0;
    gl_FragColor = vec4(color) + (n+e+s+w+ne+nw+se+sw+me) / 9.0;

 
}