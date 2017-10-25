
//variables we get from OF
uniform sampler2DRect tex;
uniform vec2 resolution;
uniform vec2 mouse;
uniform float time;
uniform float mouseDown;
uniform float amount;

#define PI 3.14159
#define TWO_PI (PI*2.0)
#define N 6.0

float size = 20.0;
float offset = 500.0;

void main(){

	vec2 st = gl_TexCoord[0].st; //coordinates of the current fragment on the incoming texture
	vec2 uv = st.xy / resolution.xy  ; //generates a uv map, a gradient in x and y

	//uv animated bump
	vec2 v = (gl_FragCoord.xy - resolution/20.0) / min(resolution.y,resolution.x) * size;
	v.x = v.x-offset;
	v.y = v.y-offset;
	float col = 0.0;

	for(float i = 0.0; i < N; i++) 
	{
	  	float a = i * (TWO_PI/N) * 60.95;
		col += cos(TWO_PI*(v.y * cos(a) + v.x * sin(a) /*+ mouse.y +i*mouse.x*/ + sin(time*0.4)*5.0 ));
	}
	
	col *= 1.1;
	uv = vec2(col, col);

    float newX = st.s + uv.x  ; //assign new positions for the fragment in X
    float newY = st.t + uv.y ; // ditto, in Y
    
    gl_FragColor = texture2DRect(tex, vec2(newX , newY));//update the position and output

	

	// DEBUGGING TESTS
	// gl_FragColor = vec4 (uv.x, uv.y, 0.0, 1.0); // uv test
//	 gl_FragColor = texture2DRect(tex,vec2(relX,relY)); // mouse test
//	 gl_FragColor = texture2DRect (tex, st); //view original texture


}