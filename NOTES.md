# Laboratorio 3, resumen de su evaluacion

**Enoc Garro Vasquez y Raul Mena Godinez**
**Nota final: 98 / 100**

| Criterio | Obtenido | Maximo |
|---|---:|---:|
| Diagrama UML coherente con el codigo | 15 | 15 |
| Encapsulacion | 13 | 15 |
| Constructores en la clase base | 15 | 15 |
| Herencia en 3 niveles e invocacion del constructor del padre | 20 | 20 |
| Miembro static y su metodo de acceso | 10 | 10 |
| Sobrecarga de operator== | 10 | 10 |
| main demostrativo | 15 | 15 |
| **Total** | **98** | **100** |

---

## Lo que hicieron bien

El diagrama UML esta muy bien resuelto. Marca static en los dos lugares, marca virtual, muestra las firmas completas con const incluido, y usa # para los atributos protected y - para los private coincidiendo exactamente con el codigo. Ese nivel de fidelidad es poco comun.

El codigo compila sin errores ni advertencias y corre correctamente.

El main muestra el contador static cuatro veces, en momentos distintos: despues de crear los personajes, despues de las copias, y al final. Asi se ve crecer el contador, que es lo que el concepto quiere mostrar. Es una forma muy clara de demostrarlo.

Cada clase derivada tiene su propio constructor de copia, y cada uno invoca al del padre. 

El constructor parametrizado delega en los setters, y validan todo, no solo lo que pedia el enunciado: el nombre vacio se sustituye por Unknown, y el mana, la fuerza y el escudo se ajustan a 0 si llegan negativos.

displayInfo encadenado con virtual y override hace que showPartyMembers muestre a cada miembro con su informacion especializada. El operator<< para Paladin tampoco se pedia y esta bien declarado como friend.

Subieron el UML al repositorio y ademas lo incluyeron en el documento. Quedo donde el enunciado lo pedia.

## Oportunidades de mejora

La unica rebaja es por el uso de protected en tres clases.

Los atributos de Character, mas meleeAttackStrength en Warrior y manaPoints en Mage, estan en protected. El enunciado lo permite unicamente donde una clase derivada necesite acceder directamente, y revisando el codigo ninguna lo necesita: Warrior::displayInfo llama a Character::displayInfo, que es un metodo, y Paladin hace lo mismo con Warrior. Todo el acceso ya pasa por la interfaz.

Fijense que en Paladin si usaron private para shieldPoints, y funciona igual. Ese es el criterio correcto para las otras tres.

La regla practica: empiecen siempre en private y suban a protected solo cuando el compilador se lo exija por una razon concreta. protected abre el atributo a todas las clases que hereden en el futuro, y eso es dificil de revertir.

Tres cosas que no afectaron la nota:

El repositorio es publico. El enunciado de este laboratorio no exige que sea privado, asi que no se penaliza, pero conviene saberlo: el codigo queda visible para cualquiera que tenga el enlace.

Hay dos archivos.cpp vacios versionados, laboratorio3-enoc-raul.cpp y main.cpp, ambos de 0 bytes. Todo el codigo esta en SolutionB.cpp. Borrenlos para que no haya dudas sobre donde esta la entrega.

No subieron la lista de autoevaluacion.

---

El detalle completo, con los puntos de cada bloque y el porque de cada rebaja, esta en
[EVALUACION.md](EVALUACION.md). Ademas, dentro del codigo quedaron comentarios marcados con `FEEDBACK:` justo en las lineas donde se detecto cada problema, con la correccion escrita. Busquen `FEEDBACK` en el proyecto.
