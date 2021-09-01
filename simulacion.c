#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>
#define ROJO "\e[31m"
#define ROJO_CLARO "\e[31;1m"
#define BLANCO "\e[37m"
#define NEGRO "\e[30m"
#define VERDE "\e[32m"
#define AZUL "\e[34m"
#define PURPURA_FUERTE "\e[35m"
#define PURPURA "\e[35;1m"
#define AMARILLO "\e[33;1m"
#define DORADO "\e[33m"
#define CIAN "\e[36m"
#define FIN "\e[0m"
#define COLOR_AMARILLO "amarillo"
#define COLOR_VERDE "verde"
#define COLOR_ROJO "rojo"
#define MAGIKARP "magikarp"
#define CARVANHA "carvanha"
#define PIKACHU "pikachu"
#define PRINTEAR_ARRECIFE "Especie:%-10s\tVelocidad:%-10i\tPeso:%-10i\tColor:%-10s\n"
#define NOMBRE_ARCHIVO_ARRECIFE "arrecife.txt"
#define NOMBRE_ARCHIVO_ACUARIO "pokes_acuario.txt"
#define MAX_FUNCIONES_REQUISITOS 5
#define MAX_FUNCIONES_MOSTRAR_ARRECIFE 5
const int MIN_FUNCION_MOSTRAR = 0;
const int MAX_FUNCION_MOSTRAR = 4;
const int IGUALDAD = 0;
const int MIN_VEL_MAX = 70;
const int MIN_PESO_MAX = 500;
const int ERROR_MAIN = -1;
const int CONTADOR_INICIO = 0;

/*
POST: imprime por pantalla un pokemon :).
*/
void mostrar_pokemon_favorito(){
	printf("pokemon favorito del alumno :):\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@@@@"PURPURA"80"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"FIN);
	printf(BLANCO"@@@@@@@@@@@@@@@@@@"PURPURA"0000GC0"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"FIN);
	printf(BLANCO"@@@@@@@@@@@@@@@@@@"PURPURA"CffL8@GL0"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"PURPURA"8GL0@880008"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"FIN);
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@"PURPURA"LtffLCGLfG8"FIN BLANCO"@@@@@@@@@@@@@@@"PURPURA"CG"FIN BLANCO"@@@@@@@@@@"PURPURA"80CLLLCfffffttG"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"FIN);
	printf(BLANCO"@@@@@@@@@@@@@@@@@@"PURPURA"01fftt1itLLffG"FIN BLANCO"@@@"PURPURA"8G"FIN BLANCO"@@@@@@@"PURPURA"LGG0"FIN BLANCO"@@@@"PURPURA"80CCCCGGGCLLffLLtC"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"FIN);
	printf(BLANCO"@@@@@@@@@@@@@@@@@@"PURPURA"ifCfft;iiifCLtG"FIN BLANCO"@@"PURPURA"CCL"FIN BLANCO"@@@@@"PURPURA"LG"FIN BLANCO"@"PURPURA"08"FIN BLANCO"@@"PURPURA"0LLC088Gf1ii11iittii"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"FIN);
	printf(BLANCO"@@@@@@@@@@@@@@@@@"PURPURA"Lf0CCL;it11;fGLtG"FIN BLANCO"@"PURPURA"C@"PURPURA"L0"FIN BLANCO"@@@"PURPURA"CL00Cf0CC8@"PURPURA"8Cf1iiii;iffffLCf18"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"FIN);
	printf(BLANCO"@@@@@@@@"PURPURA"8fCGG08"FIN BLANCO"@@"PURPURA"t@@"PURPURA"0GCi1t1i;tGLftLC8CtLGffGCft1L88Gtii1111111;;LLLGG0ff"FIN BLANCO"@@@"PURPURA"0C0"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@"PURPURA"0CCG0GGGfC880Gt1t1iii0CfLtG0LL11fGCffG80L1ii11111i11i1:1LCG08@"PURPURA"t8000C8"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@"PURPURA"0CC08@"PURPURA"0LLLLLLi1t1i;G8GG8@8GCGGCCGGGCfiiiii1tt1111111;iCCG0@0f088C8"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@\n"FIN);
	printf(BLANCO"@@@@@@@@@@@@@"PURPURA"8GLfCG0GGCLt1t1:tGGG0@@@@00GCCCCCCt1i;iitftttt1111;tCCG80L0@"PURPURA"8C8"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@"PURPURA"0LfLG0GGLLLLLCLC08@@@@@80CCGGCGG0GLtii1tftt11i;1CGGCLtLGGC"FIN BLANCO"@@@@"PURPURA"888"FIN BLANCO"@@@@@@@@@@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@"PURPURA"8G1fGGCLffLLG0008@@@@@@0CGGGGGG0880Ctiitt11i1LLLfttLLLtfGCGG00f"FIN BLANCO"@@@@@@@@@@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@@"PURPURA"0i1fCCCLfttffLCG0@@8CtfGGG00000008@8Lti:i1t1i;1ttttttLG08@@"PURPURA"G0"FIN BLANCO"@@@@@@@@@@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@@@"PURPURA"8tCtLCGCCLLLLCCCGLLG0GG0GCCG00008@@@@CtttfLG888880GCCLLCCL8"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@@"PURPURA"8L8@CLCCGGGCC00fi.G@80800GGG0000008GCG0ff8@@@@@@@@@@@@8L11"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@@"PURPURA"LG@8@0LCCCCff8f:;,tCG808@8000000008Gf11G@@@@@@@@@@8888880LL"FIN BLANCO"@@@@@@@@@@@@@@"PURPURA"00"FIN BLANCO"@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@"PURPURA"GC@@@88GCGGGLfffGC8@@@0LLCCCCLLG00CLLC1C@@@8G@@@@@800CLfffLtt"FIN BLANCO"@@@@@@@"PURPURA"80000CtL"FIN BLANCO"@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@"PURPURA"f@@@@880GCCCGG0@@@@80GfL@GiG@8GC0CiCGC18@@@@8@8@80GLtfLLLLff1f8"FIN BLANCO"@"PURPURA"80GGG00GLf0"FIN BLANCO"@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@"PURPURA"f8@@@8888GCGGGCLLt1iiiii8@Gt8000GifCGCtGG08@@@@8CLttG8@"PURPURA"88GCLf1:1tfC08GLfG"FIN BLANCO"@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@"PURPURA"GG@@@0GGCLtttttttftft1t:tGLGGGGGt1LLGti0GG00000CLf;8@@@@8CCGCGCCLttfffG"FIN BLANCO"@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@"PURPURA"8tL0C111i iLLCCLLff1;1CfCCCCCLffitffti;C0CCCCCGLC::8880GG0@@@@@@@@0LiL088"FIN BLANCO"@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@@"PURPURA"0ttiC1tL:;LfL1Lt:LLfCCLftftt111tLG0G0CiffLfffffft1CGC08@@@@@@@@@@80fCGGGf8"FIN BLANCO"@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@"PURPURA"0GG@fL@Gtff ,LG1LGCCCLffi,itfffLG8@@@@88G1:f888CiCGGC0@@@@@@@@88800GfL@@@@LC"FIN BLANCO"@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@"PURPURA"0C08@@GiLGCt1t1tLGGGCLLC0880Cf110@@@@@@@@@@@Gtf0C0@@@@8f8888880GGGGCGff00@@8C8"FIN BLANCO"@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@"PURPURA"LC8@@880L111ttt1GGGG08@@@@88888CL@@@@@@@@@@@@@f1ftLfCCGfLGGGGCCCCCCCCffG088GG"FIN BLANCO"@@@@@@@@\n");
	printf(PURPURA"8CG8"FIN BLANCO"@@@@@@@@@"PURPURA"0fG@@880GCCCL1i1i1@@@@@@@@@888000Cf@@@@@@@@@@@@@Ltftt;tftfCCCCCCCCCCCCLfGGGLifG0GGGGCC"FIN BLANCO"@\n");
	printf(PURPURA"C08G0"FIN BLANCO"@@@@@@@"PURPURA"810@@@80CLCCCLfft1t@@@@@@@@@8000000t8@@@@@@@@@@888LtGGCLfCCCCCCCCLLCLCftCff1itiifCCCLLG"FIN BLANCO"@\n");
	printf(PURPURA"CG@@GG"FIN BLANCO"@@@@@@"PURPURA"ff@@@8GCCCCCftffiGCf@@@@@@@@0000000fL@@@@@@@@88000Gff0@@tLCCCCCCCCLLLftt11;f@0f;iLfG8"FIN BLANCO"@@@\n");
	printf(PURPURA"8f@@@0LG"FIN BLANCO"@@@@"PURPURA"t0@@8GLCCCLftt1t0"FIN BLANCO"@@"PURPURA"Lf0@@@@@@0G000GGL,fGG000GGGGGGGGGL;1tttftttttt11iii1ttff10@@Gi;8"FIN BLANCO"@@@@@\n");
	printf(BLANCO"@"PURPURA"LG@@@8CL0"FIN BLANCO"@@"PURPURA"tG@80GCCLft11fG"FIN BLANCO"@@@@@"PURPURA"8ttC0880GGCCLLLfftttfffLCCGGGGGCGCf1i1i1fLLLLCLfL1;1tfL1f88@@LL"FIN BLANCO"@@@@@\n");
	printf(BLANCO"@"PURPURA"8t8888@0CC00iCLfCLf1tLC8"FIN BLANCO"@80GGGC"PURPURA"1L8t1LfLLLLCGGGGG0GCCLftttttffLLffLLCt0@@@@@@@8GG0f;t11ft088@@0L8"FIN BLANCO"@@@\n");
	printf(BLANCO"@@"PURPURA"G180G0@@8GGL1f1LGLG"FIN BLANCO"@@@8G08@@@8C"PURPURA"1GG1G0088@@@@@8000000000GCCLffLLCCG1L@@@@@8888CCCGfiLf;iG088@@0i8"FIN BLANCO"@@\n");
	printf(BLANCO"@@@"PURPURA"Li00CGG08@80ftfLL088CG@@@@@"PURPURA"80GL1CL1C8@@@@8800GLLLLLLLCCGGG0GGCCCC1@@@@@@@80GCCCCG1iGCiCGG0@@8Lf"FIN BLANCO"@@\n");
	printf(BLANCO"@@@@"PURPURA"GtG0GGGG08CL000GCCtG@@@@"PURPURA"80GCCLt1LCi,LCGGGGGGGGGGGCLLffttttffffLiL@@@@@80GCLCCCCLLi10GtCCC0@C00f"FIN BLANCO"@\n");
	printf(BLANCO"@@@@@"PURPURA"8ffGGCCGCtGGGG08CC@880GGCCCLfL1tCi t@8@@@@@@@@@@@@80GGCCLffffftG@@@8GCLLCCCCCCLf1;1ffLCC00L@@fG\n"FIN);
	printf(BLANCO"@@@@@@@"PURPURA"C1tLCCCfCCGCG0iG0GGCCCCCLfLLf;t:  C@@@@@@@@@@@8800GGGGGGGCt8Ct@880CLCCGCCCLLfLi1Ci;fCCLL8@@0f\n"FIN);
	printf(BLANCO"@@@@@@@@"PURPURA"8Ct1tftfCCCG011CLLLLLLffft111ff.  f@@@@@@@@@@@800G00GGGGfC@8tt8GLCCCLLfffttt1;tLG;iLffC0888t\n"FIN);
	printf(BLANCO"@@@@@@@@@@@"PURPURA"Gf11iitffLf;itfftt11111ttfCGL;. iG@@@@@@@@@@80GGGGGGCt@@@@LtCCCffttttfff1;1tC80;1fCC008GL\n"FIN);
	printf(BLANCO"@@@@@@@@@@@@@"PURPURA"8GL1ii1tttt1t111tttfffLCCCCGCfti1C0@@@@@8800GGGGGGLf@@@@@Gttt1111ttttiitttG@GitfLCG08L8\n"FIN);
	printf(BLANCO"@@@@@@@@@@@@@@@@@"PURPURA"8GCLiG8GCCCCLLffLLCCCCLffff1tf1tLC0880000GGGCCCi@@@@@8GLf11i;;iiii11ifCGt11fLLGGL0"FIN BLANCO"@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@@"PURPURA"811CLffftLCCCCCCCLLfffffifGGCLfffftffffLLLLCt1@@@@8GGGCCLftt111t1ifLii111fftf0"FIN BLANCO"@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@"PURPURA"8008800GGCLf1fLLLffttfttti1LffffLLLftt1i1i11ttL1f@@880CLLffffLLLffttLf:11i;itC"FIN BLANCO"@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@"PURPURA"8C0080GCLLLCGGLfLLCCG0088008@@8880000000000088@@8L0880GLftfLftt11fCCCLLLi;1tL0"FIN BLANCO"@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@"PURPURA"8CCGG0088"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"PURPURA"8f1tt1fC0@@@@000Cti1ffftf0"FIN BLANCO"@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"PURPURA"8GC1LG00000GCGCCLi1tLG"FIN BLANCO"@@@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"PURPURA"80GGCCCCCLCG8"FIN BLANCO"@@@@@@@@@@@@@@@@@\n");
	printf(BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\n"FIN);
}
/*
POST: imprime por pantalla el logo de pokemon.
*/
void mostrar_logo(){
	printf(AMARILLO"                                .::.\n");
	printf(AMARILLO"                              .;:**'            \n");
	printf(AMARILLO"                              `                  \n");
	printf(AMARILLO"  .:XHHHHk.              db.   .;;.     dH  MX   \n");
	printf(AMARILLO"oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN\n");
	printf(AMARILLO"QMMMMMb  'MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM\n");
	printf(AMARILLO"  `MMMM.  )M> :X!Hk. MMMM   XMM.o'  .  MMMMMMM X?XMMM MMM>!MMP\n");
	printf(AMARILLO"   'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `'' MX MMXXMM\n");
	printf(AMARILLO"    ~MMMMM~ XMM. .XM XM`'MMMb.~*?**~ .MMX M t MMbooMM XMMMMMP\n");
	printf(AMARILLO"     ?MMM>  YMMMMMM! MM   `?MMRb.    `'''   !L'MMMMM XM IMMM\n");
	printf(AMARILLO"      MMMX   'MMMM'  MM       ~m:           !Mh.''' dMI IMMP\n");
	printf(AMARILLO"      'MMM.                                             IMX\n");
	printf(AMARILLO"       ~M!M                                             IMP\n\n\n\n\n"FIN);
}
/*
PRE: el puntero recibido debe apuntar a algo.
POST: retorna true si el pokemon cumple los requisitos pedidos, caso contrario,
	retorna false.
*/
bool es_magikarp_shiny(pokemon_t * pokemon){
	return ((strcmp(((*pokemon).color), COLOR_AMARILLO) == IGUALDAD) && (strcmp(((*pokemon).especie), MAGIKARP) == IGUALDAD));
}
/*
PRE: el puntero recibido debe apuntar a algo.
POST: retorna true si el pokemon cumple los requisitos pedidos, caso contrario,
	retorna false.
*/
bool es_flash(pokemon_t * pokemon){
	return((strcmp(((*pokemon).color), COLOR_ROJO) == IGUALDAD) && ((*pokemon).velocidad >= MIN_VEL_MAX));
}
/*
PRE: el puntero recibido debe apuntar a algo.
POST: retorna true si el pokemon cumple los requisitos pedidos, caso contrario,
	retorna false.
*/
bool esta_gordito(pokemon_t * pokemon){
	return((*pokemon).peso >= MIN_PESO_MAX);
}
/*
PRE: el puntero recibido debe apuntar a algo.
POST: retorna true si el pokemon cumple los requisitos pedidos, caso contrario,
	retorna false.
*/
bool es_carvanha_shiny(pokemon_t * pokemon){
	return((strcmp(((*pokemon).color), COLOR_VERDE) == IGUALDAD) && (strcmp(((*pokemon).especie), CARVANHA) == IGUALDAD));
}
/*
PRE: el puntero recibido debe apuntar a algo.
POST: retorna true si el pokemon cumple los requisitos pedidos, caso contrario,
	retorna false.
*/
bool es_pikachu_surf(pokemon_t * pokemon){
	return(strcmp((*pokemon).especie, PIKACHU) == IGUALDAD);
}
/*
PRE: el puntero recibido debe apuntar a algo.
POST: imprime por pantalla el pokemon recibido en forma de lista.
*/
void mostrar_arrecife_lista(pokemon_t * pokemon){
	pokemon_t * pokemon_aux = NULL;
	pokemon_aux = pokemon;
	printf(PRINTEAR_ARRECIFE, (*pokemon_aux).especie, (*pokemon_aux).velocidad, (*pokemon_aux).peso, (*pokemon_aux).color);
	printf("\n");
}
/*
PRE: el puntero recibido debe apuntar a algo.
POST: imprime por pantalla el pokemon recibido en forma de recuadros.
*/
void mostrar_arrecife_recuadro(pokemon_t * pokemon){
	pokemon_t * pokemon_aux = NULL;
	pokemon_aux = pokemon;
	printf("\n|  nombre      |  color       |      peso        |      velocidad      |");
	printf("\n------------------------------------------------------------------------");
	printf("\n|  %-10s  |  %-10s  |      %-10i  |       %-10i    |",(*pokemon_aux).especie,(*pokemon_aux).color, (*pokemon_aux).peso, (*pokemon_aux).velocidad);
    printf("\n-----------------------------------------------------------------------");
}
/*
PRE: el puntero recibido debe apuntar a algo.
POST: imprime por pantalla el pokemon recibido en forma escalonada.
*/
void mostrar_arrecife_escalonado(pokemon_t * pokemon){
	pokemon_t * pokemon_aux = NULL;
	pokemon_aux = pokemon;
	printf("Pokemon: %s.\n", (*pokemon_aux).especie);
	printf("\tColor: %s.\n", (*pokemon_aux).color);
	printf("\t\tPeso: %i.\n", (*pokemon_aux).peso);
	printf("\t\t\tVelocidad: %i.\n\n", (*pokemon_aux).velocidad);
}
/*
PRE: el puntero recibido debe apuntar a algo.
POST: imprime por pantalla el pokemon recibido con forma de pokedex.
*/

void mostrar_arrecife_pokedex(pokemon_t * pokemon){
	pokemon_t * pokemon_aux = NULL;
	pokemon_aux = pokemon;
	printf(ROJO"iiiiiiiiiii;iiii;iii;iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiit"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"FIN);
	printf(ROJO"ii"FIN CIAN";tff""LL"FIN ROJO"f1"FIN AMARILLO"ii"FIN ROJO";;"FIN AZUL"ii"FIN ROJO";;"FIN VERDE"ii"FIN ROJO";;1;iiiiiiiii"FIN ROJO_CLARO";;;;;;;;;;;;;;;;;;;i;t"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf(ROJO"i"FIN CIAN";LCLCGGCL"FIN ROJO"f1;;;ii1ii;i;iiiii"FIN ROJO_CLARO";:,,"FIN ROJO":::::::::::::::::;;;;;"FIN ROJO_CLARO";"FIN ROJO"tttttttffLCG8"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf(ROJO"ii"FIN CIAN"8tLLLLLL"FIN ROJO"fLiiiiiiiiiiiii"FIN ROJO_CLARO";:,,:;;"FIN ROJO"iiiiiiiiiiiiiii"FIN ROJO_CLARO";;"FIN ROJO"iiiii"FIN ROJO_CLARO";:::::::::,,:;"FIN ROJO"1L0"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf(ROJO"i"FIN CIAN";CGLLLLLL"FIN ROJO"Ct;iiiiiiiii"FIN ROJO_CLARO";::::;"FIN ROJO"iiiiiiiiiiiiiiiiiiii"FIN ROJO_CLARO";"FIN ROJO"iiiii"FIN ROJO_CLARO";:"FIN ROJO"iiiiiii"FIN ROJO_CLARO";;;:,,:;"FIN ROJO"tC8"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf(ROJO"ii"FIN CIAN";fCCCCC"FIN ROJO"Ltiiiiiiii"FIN ROJO_CLARO";;:::;"FIN ROJO"iiiiiiiiiiiiiiiiiiiiiii"FIN ROJO_CLARO":;;;;::;"FIN ROJO"iiiiiiiiiiii"FIN ROJO_CLARO";::,:"FIN ROJO"if0"FIN BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf(ROJO";;;;;"FIN CIAN"iii"FIN ROJO";;;;;;;::::"FIN ROJO_CLARO"::;;"FIN ROJO"iiiiiiiiiiiiiiiiiiiiiiiii"FIN ROJO_CLARO":;;;;::;"FIN ROJO"iiiiiiiiiiiiiii"FIN ROJO_CLARO";:,::"FIN ROJO"1fG08"FIN BLANCO"@@@@@@@@@@@@@@@@@@@\n");
	printf(ROJO":"FIN ROJO_CLARO"::::::::::,,,,,:;;;"FIN ROJO"iiiiiiiiiiiiiiiiiiiiiiiiiiii"FIN ROJO_CLARO";iiiii:;"FIN ROJO"iiiiiiiiiiiiiiiii"FIN ROJO_CLARO";::,,::;"FIN ROJO"i11t111111111111111\n"FIN);
	printf(ROJO"i"FIN ROJO_CLARO";"FIN ROJO"1ttttttttttttt1;tiittttttttttttttttttttttttti"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"iiiiiiiiiiiiiiiiiiii"FIN ROJO_CLARO";;:,:::::::::::::::::,,"FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"CLCCCCCCCCCCCCLtCffCCCCCCCCCCCCCCCCCCCCCCCCCf"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"ii;;;;;;;;;;;;;;;;;;iiiii;;;;;;;;;;;;;;ii:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"Lf                                        0fL"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;;                                    ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"Lf                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;    "FIN AMARILLO" NOMBRE: %-10s              "FIN ROJO";i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN,(*pokemon_aux).especie);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL     "AMARILLO" no hay coneccion a internet,    "FIN ROJO"  0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL     "AMARILLO" no se puede mostrar imagen del   "FIN ROJO" 0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;   "AMARILLO"  COLOR: %-10s              "FIN ROJO" ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN,(*pokemon_aux).color);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL     "AMARILLO"           pokemon...             "FIN ROJO" 0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;    "AMARILLO"  PESO: %i.                    "FIN ROJO"  ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN, (*pokemon_aux).peso);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"LL                                        0ff"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"Cf0888888888888888888888888888888888888888GfL"FIN ROJO_CLARO";;iiiii;;"FIN ROJO"i;   "AMARILLO"  VELOCIDAD: %i.                 "FIN ROJO" ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN, (*pokemon_aux).velocidad);
	printf(ROJO";"FIN ROJO_CLARO";"FIN ROJO"tLLLLLfttLLLLLLLLLLLLLLLLLLLLLLfttttttttfLLCf"FIN ROJO_CLARO";;;;;;;:;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO"ii"FIN ROJO_CLARO";;"FIN ROJO"tCCL;i;1CCCCCCCCCCCCCCCCCCCCCfi111111itCCCf"FIN ROJO_CLARO";:;;;:::;"FIN ROJO"i;                                     ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO"iii"FIN ROJO_CLARO";:;"FIN ROJO"tLfttLCLLLLLLLLLLLLLLLLLLLCfttttttttfCLCt"FIN ROJO_CLARO";;;;ii;:;"FIN ROJO"i;;                                    ;i:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO"iiiii"FIN ROJO_CLARO";;;"FIN ROJO"iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii;"FIN ROJO_CLARO"i;iiiii;;"FIN ROJO"iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO"iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"FIN ROJO_CLARO"i;iiiii;;"FIN ROJO"iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO"iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"FIN ROJO_CLARO"i;iiiii;;"FIN ROJO"iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii:"FIN ROJO_CLARO","FIN ROJO";\n"FIN);
	printf(ROJO"iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"FIN ROJO_CLARO"i;iiiii;;"FIN ROJO"iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii:"FIN ROJO_CLARO","FIN ROJO";\n");
	printf(ROJO";"FIN ROJO_CLARO";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;:;;;;;:;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;::"FIN ROJO"f\n"FIN);
	printf(ROJO"::::::::::::::::::::::::::::::::::::::::::::::::,,::::tLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLC0@\n"FIN);
	
	printf("\n\n\n");
}
/*
PRE: el puntero recibido debe apuntar a algo.
POST: imprime por pantalla el pokemon recibido con forma de pikachu informando.
*/
void mostrar_arrecide_pikachu(pokemon_t* pokemon){
	pokemon_t * pokemon_aux = NULL;
	pokemon_aux = pokemon;
	printf("\t\t\t_____________________\n");
	printf("\t\t\t|Pokemon: %-10s.|____\n", (*pokemon_aux).especie);
	printf("\t\t\t|\tColor: %-10s.|______\n", (*pokemon_aux).color);
	printf("\t\t\t|\t\tPeso: %-10i.|_____________\n", (*pokemon_aux).peso);
	printf("\t\t\t|\t\t\tVelocidad: %-10i.|\n", (*pokemon_aux).velocidad);
	printf("\t\t\t|     ________________________________________|\n");
	printf("\t\t\t|    /\n");
	printf("\t\t\t|   /\n");
	printf("\t\t\t|  /\n");
	printf("\t\t\t| /\n");
	printf("\t\t\t|/\n");
	printf(AMARILLO" ,     ,\n");
	printf(AMARILLO" |`\\    `;;,            ,;;'\n");
	printf(AMARILLO" |  `\\    \\ '.        .'.'\n");
	printf(AMARILLO" |    `\\   \\  '-''''-' /\n");
	printf(AMARILLO" `.     `\\ /          |`\n");
	printf(AMARILLO"   `>    /;   _     _ \\ \n");
	printf(AMARILLO"    /   / |       .    ;\n");
	printf(AMARILLO"   <  (`';\\ "FIN ROJO"()"FIN AMARILLO"   ~~~  "FIN ROJO"("FIN AMARILLO"/_\n");
	printf(AMARILLO"    ';;\\  `,     __ _.-'` )\n");
	printf(AMARILLO"      >;\\          `   _.'\n");
	printf(AMARILLO"      `;;\\          \\-'\n");
	printf(AMARILLO"        ;/           \\ _\n");
	printf(AMARILLO"        |   ,"".     .`  \\\n");
	printf(AMARILLO"        |      _|   '   /\n");
	printf(AMARILLO"         ;    /'')     .;-,\n");
	printf(AMARILLO"         \\    /  __   .-'\n");
	printf(AMARILLO"          \\,_/-'`  `-'\n"FIN);
	

}
/*
POST: retorna true si el numero recibido esta entre los parametros definidos.
*/
bool numero_valido(int respuesta){
	return ((respuesta >= MIN_FUNCION_MOSTRAR) && (respuesta <= MAX_FUNCION_MOSTRAR));
}
/*
POST: le pregunta al usuario en que forma quiere que se muestren los pokemones
	del arrecife.
*/
int preguntar_tipo_mostrar(){
	int respuesta;
	printf("ingrese forma de mostrar el censo de pokemones:\n");
	printf("'0' = forma de lista\n");
	printf("'1' = forma de recuadro\n");
	printf("'2' = forma escalona\n");
	printf("'3' = forma pokedex\n");
	printf("'4' = forma pichachu saludando\n");
	scanf(" %i", &respuesta);
	while(!numero_valido(respuesta)){
		printf("numero no valido...\n");
		printf("ingrese forma de mostrar el censo de pokemones:\n");
		printf("'0' = forma de lista\n");
		printf("'1' = forma de recuadro\n");
		printf("'2' = forma escalona\n");
		printf("'3' = forma pokedex\n");
		printf("'4' = forma pichachu informando\n");
		scanf(" %i", &respuesta);
	}
	return respuesta;
}
/*
POST: imprime por pantalla un pikachu impactado.
*/
void mostrar_pikachu(){
	printf(DORADO"\n\n\n@@888@@888@@88@@@88@@888@@888@@88@@@88@@888@@888@@88@@@88@@@88@@888@@88@@@88@@@88@@888@@88@@@88@@@88\n88@@@@8@@888@@888@@88@@@88@@@88@@888@@888@@88@@@88@@888@@888@@88@@@88@@888@@888@@88@@@88@@888@@888@@\n@@8 CG08@@@@888@@88@@888@@888@@88@@@88@@888@@888@@88@@@88@@888@@888@@88@@@88@@888@@888@@888@@88@@@88\n@@8:,::;ifG08@@@@888@888@@888@@88@@@88@@888@@888@@88@@@88@@888@@888@@888@@88@@888@@888@@888@@8888888\n88@0::::,;fttfCG8@@@88@@88@@@88@@888@@888@@88@@@88@@888@@888@@88@@@88@@888@@888@@88@@@88@@888@@@@@@@\n@@8@G::;:1C  ftttfC0@@88@@888@@88@@@88@@888@@888@@88@@@88@@@88@@888@@88@@@88@@@88@@888@@@@@@@8080888\n88@@@0;::1       fttt 0@@8@@888@@888@@88@@@88@@@88@@888@@888@@88@@@88@@888@@888@@88@@@880GCfffi:,C@@\n@@888@8i,;           ftt G8@@@@88@@@88@@888@@888@@88@@@88@@888@@888@@88@@@88@@@@@@8GC ttttfff i::C@8\n88@@@88@t,t             ftf G8@@@888@@888@@88@@@88@@888@@888@@88@@@88@@88@@@@80C ftttff       ;:,C@8\n888@@88@@t:                ftt 0@@88@@888@@88@@888@@888@@888@@88@8888@@@@80Cftttff           f::t88@\n@@888@@88@ ;                  ftf0@@88@@888@@888@@88@@@88@@888@@88@@@0C ftttf                i,i@@88\n88@@@88@@8@Cif                  ftf0@@@@@@@@@@@@88@@@88@@88@@@@@@8G ftttf                   t,1888@@\n@@888@@888@@Git                   ftfGGGCCCC   ffffffffffffff  Cfttff                      t: @@@@88\n88@@@88@@888@8t1                    ftttffffffffff          fffff                         tiG@@888@@\n@@888@@888@@88@C1t                                                                       1f@@88@@@88\n@@888@@8888@888@8f1f                                                                   ttG@888888888\n88@@@88@@888@@88@@Gftf   ff                                                          tt 8@888@@888@@\n@@888@@888@@88@@@8@@0ftfttf                                                 f     fttC8@88@@@88@@@88\n88@@@88@@@88@@888@@88@ ;f                                                   t1t ttfG@@88@@888@@888@@\n@@888@@888@@88@@@88@@Gi                                                       t;C@@@88@@888@@88@@@88\n88@@@88@@888@@888@@88;f         fttf                          fttf             ft888@@88@@888@@888@@\n8888888888888888888@1t         1f 1:;f                       tf 1:;f            t1@88888888888888888\n@@888@@888@@88@@@8@ i         1;G8f::;                      t:G8 ::;             1f@88@@888@@88@@@88\n88@@@88@@888@@888@0;          t,::::,i                      f:,:::,i              i0@@88@@888@@888@@\n@@888@@888@@88@@8@1t           ti;;;1                        fi;;;1               tt@8@@88@@@88@@@88\n88@@@88@@@88@@88@Gi                         ftttf                                  i0@88@@888@@888@@\n@@888@@888@@88@@@1t    ff                   t;::;f                      ff         ft@@@888@@88@@@88\n8888888@8888@@8@G; ft111111t                                        ft111111tf      1G@8@8888@@888@@\n88@@@88@@888@@8@f1 11111111i1                                      f111111111it     f188@@888@@888@@\n@@888@@888@@88@@1ffi11111111if              fttttttttf             1i1111111111      1G@888@@88@@@88\n88@@@88@@@88@@881f t11111111f              11tfffffft1t            f1111111111f      f18@@888@@888@@\n@@888@@888@@888@f1   ffttff               ti          if             tt11111tf        1G@8@@@88@@@88\n88@@@88@@888@@880i                        fif    ff f it                              ft@@888@@888@@\n@@888@@888@@88@8@Ci                        f1ttffffff1i                                iG@8@@88@@888\n@@888@@888@@88@@8@Ci                         ftttttttt                                 tf@8@@88@@@88\n88@@@88@@888@@888@@ i                                                                  f1@@88@@888@@\n@@888@@888@@88@@@88@Ci                                                                  iC@@@88@@@88\n88@@@88@@@88@@888@@8@C1                                                                 tf@88@@888@@\n@@888@@888@@88@@@88@@0;                                                                 f1@@@88@@@88\n88@@@88@@888@@888@@8@11                                                                  i888@@888@@\n88@@@88@@888@@888@@@01C CC   CC  CCC  CC   CC   CC  CCC  CCC  CC   CC  CCC  CCC  CC   CCCt0@8@@888@@\n@@888@@888@@88@@@88@@888@@888@@88@@@88@@888@@888@@888@@88@@888@@888@@888@@88@@888@@888@@888@@88@@@88\n88@@@88@@@88@@888@@88@@@88@@@88@@888@@88@@@88@@@88@@888@@888@@88@@@88@@888@@888@@88@@@88@@888@@888@@\n"FIN);
}

int main (int argc, char * argv[]){
	if(argc <= 1){
		printf(CIAN"es nesario que ingrese el nombre del archivo arrecife para comenzar el programa\n\n\n"FIN);
		printf(ROJO_CLARO"el programa cuando acurre el problema:\n"FIN);
		mostrar_pikachu();
		return ERROR_MAIN;
	}
	mostrar_logo();
	mostrar_pokemon_favorito();
	arrecife_t * arrecife = NULL;
	acuario_t * acuario = NULL;
	arrecife = crear_arrecife(argv[1]);
	if(arrecife == NULL){
		printf("no se pudo crear el arrecife...\n");
		mostrar_pikachu();
		return ERROR_MAIN;
	}
	acuario = crear_acuario();
	if(acuario == NULL){
		printf("no se pudo crear el acuario...\n");
		mostrar_pikachu();
		return ERROR_MAIN;
	}
	bool (*funciones_requisitos[MAX_FUNCIONES_REQUISITOS])(pokemon_t *);
	funciones_requisitos[0] = es_magikarp_shiny;
	funciones_requisitos[1] = es_flash;
	funciones_requisitos[2] = esta_gordito;
	funciones_requisitos[3] = es_carvanha_shiny;
	funciones_requisitos[4] = es_pikachu_surf;
	void(*funciones_mostrar_arrecife[MAX_FUNCIONES_MOSTRAR_ARRECIFE])(pokemon_t *);
	funciones_mostrar_arrecife[0] = mostrar_arrecife_lista;
	funciones_mostrar_arrecife[1] = mostrar_arrecife_recuadro;
	funciones_mostrar_arrecife[2] = mostrar_arrecife_escalonado;
	funciones_mostrar_arrecife[3] = mostrar_arrecife_pokedex;
	funciones_mostrar_arrecife[4] = mostrar_arrecide_pikachu;
	int i = CONTADOR_INICIO;
	while(i < MAX_FUNCIONES_REQUISITOS){
		int cantidad_pokemon =rand () % 5 + 1;
		int resultado = trasladar_pokemon(arrecife, acuario, funciones_requisitos[i], cantidad_pokemon);
		if(resultado == ERROR_MAIN){
			printf("ocurrio un problema con la funcion de requisito nº %i\n", i+1);
		}
		printf("%iº censada:\n", i+1);
		int respuesta = preguntar_tipo_mostrar();
		censar_arrecife(arrecife, funciones_mostrar_arrecife[respuesta]);
		printf("\n\n\n\n\n");
		i++;
	}
	int resultado;
	if(argc == 2){
		printf("se creara el archivo pokes_acuario.txt para guardar los pokemones dentro del acuario.\n");
		resultado =  guardar_datos_acuario(acuario,NOMBRE_ARCHIVO_ACUARIO);
	}else resultado =  guardar_datos_acuario(acuario, argv[2]);
	if(resultado == ERROR_MAIN){
		printf("ocurrio un problema al crear el archivo que guarda los pokemones dentro del acuario...\n");

	}
	liberar_acuario(acuario);
	liberar_arrecife(arrecife);
	return 0;
}