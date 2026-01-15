Manguita dijo que anote todo. Hacele caso.
	"v" Tengo que mutear en el strchr el hecho de separadores mas alla que el ' '. //Estaba bien gestionado, solo debia ajustar al subject
	"v" El caso de string vacio o con solo espacios, debe tambien de tomarse como error. // Esto estaba en el arg_parse en check de !token
	"v"	Modificar el str_manager y que si sale null el output, que si uno de los argv es NULL, o vacio, o solo espacios.. de error.
	"x" Crear el tester a la par. El del Make, parseo, gestor de errores y casos especiales. // I think it not gonna happen :/
	crear los movimientos
	decidir el algoritmo. //pendiente de investigar K-sort.


Optimizaciones para el futuro.

1. Análisis del rr (Double Rotate)

En el log que me pasaste, la instrucción rr se ejecutó 128 veces.

    ¿Es beneficioso? Totalmente. Cada rr te ahorra exactamente 1 movimiento comparado con hacer ra y luego rb por separado.

    Ahorro real: Has ahorrado 128 movimientos solo con esa línea de código. En un proyecto donde la diferencia entre una nota de 80 y 100 pueden ser 200 movimientos, el rr es una herramienta clave.

2. Puntos de ajuste para reducir movimientos

Mirando tu flujo de movimientos, hay tres áreas donde podemos "rascar" más puntos:
A. El "coste" de rb vs rr en la Fase 1

He notado que en tu código haces esto:
C

if (*src && (*src)->index > (k + i))
    rr(src, dst);
else
    rb(dst);

Esto envía los números más pequeños del bloque al fondo de B. Es bueno porque "pre-ordena" un poco la pila B (poniendo los muy pequeños abajo y los medianos arriba).

Sugerencia de ajuste: A veces, hacer rb(dst) sistemáticamente puede ser contraproducente si el número que queda en la cima de A es justo el que necesitas a continuación. Podrías probar a usar rr solo si el index de *src está realmente lejos, o incluso testear qué pasa si quitas el rb simple y solo dejas el rr.
B. Optimización de rrb en la Fase 2 (Hacia Stack A)

En tu lista de movimientos veo secuencias largas de rb o rrb seguidas de pa.
Plaintext

rrb
rrb
rrb
rrb
pa

Esto significa que tu algoritmo está buscando el número más grande en B y rotando hasta que llega a la cima. El ajuste "Pro": En lugar de buscar solo el número N, busca el N y el N−1 (el más grande y el segundo más grande). Si el N−1 está más cerca de la cima, pásalo a A, luego busca el N, pásalo a A y haz un sa. Esto se llama "Two-element lookahead" y puede bajar otros 200-400 movimientos.
C. La "Ventana" Dinámica

Tu k ahora es 35. Pero nota esto: a medida que la Stack A se vacía, la densidad de números que cumplen la condición cambia.

    Ajuste: Algunos estudiantes de 42 usan un k que se reduce ligeramente a medida que size de A disminuye. Sin embargo, con un valor fijo de 35-40 ya deberías obtener la máxima puntuación si la fase 2 es eficiente.

3. Diagnóstico de tu log

He detectado algo curioso al final de tu log:
Plaintext

rb
rb
rb
pa
pa
rrb
rrb
rrb
rrb
pa

Esas rotaciones (rb y luego rrb) indican que tu "perrito" está trabajando bien: decide si ir por el camino corto (arriba) o por el largo (abajo).

¿Cuál es tu siguiente paso? Si quieres reducir aún más, te recomiendo implementar la lógica de "buscar el más grande y el segundo más grande" en push_b_to_a.
