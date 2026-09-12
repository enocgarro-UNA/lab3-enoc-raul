# Evaluación del Laboratorio 3

**Integrantes:** Enoc Garro Vásquez · Raúl Mena Godínez
**Repositorio:** https://github.com/enocgarro-UNA/lab3-enoc-raul
**Nota: 98 / 100**

| # | Criterio | Puntos |
|---|---|---:|
| 1 | Diagrama UML coherente con el código | 15 / 15 |
| 2 | Encapsulación | 13 / 15 |
| 3 | Constructores en la clase base | 15 / 15 |
| 4 | Herencia en 3 niveles e invocación del constructor del padre | 20 / 20 |
| 5 | Miembro `static` y método de acceso | 10 / 10 |
| 6 | Sobrecarga de `operator==` | 10 / 10 |
| 7 | `main` demostrativo | 15 / 15 |
| | **Total** | **98 / 100** |

---

## Lo que quedó bien

**El diagrama UML está muy bien resuelto.** Está completo y usa la notación con precisión:

- `{static}` marcado en `totalCharactersCreated` y en `getTotalCharactersCreated()`.
- `virtual` marcado en `~Character()` y `displayInfo()`.
- Las firmas completas, con `const` incluido: `+ getName() const : std::string`.
- **Usa `#` para los atributos `protected` y `-` para los `private`**, y coincide exactamente con el código: `#` en `Character`, `Warrior` y `Mage`; `-` en `Paladin` y `AdventuringParty`. Ese nivel de fidelidad es poco común.
- Los tres triángulos de herencia con la punta del lado del padre, mostrando `Character`, `Warrior` y `Paladin` en ese orden, y el rombo de agregación hacia `AdventuringParty`.

**El código compila sin errores ni advertencias y corre correctamente.** Se verificó con MSVC:

```
Original: Name: Ares | Level: 5 | HP: 120
Copia:  Name: Ares (Copia) | Level: 5 | HP: 50   <- independientes
hero == sameLevel = true
hero == differentLevel = false
Contador final: 9
```

**El `main` muestra el contador `static` cuatro veces**, en momentos distintos: después de crear los personajes (4), después de las copias (7), y al final (9). Así se ve **crecer** el contador, que es lo que el concepto quiere mostrar. Es una forma muy clara de demostrarlo.

**Cada clase derivada tiene su propio constructor de copia, y cada uno invoca al del padre:**

```cpp
Warrior::Warrior(const Warrior& other) : Character(other), meleeAttackStrength(other.meleeAttackStrength) {}
Paladin::Paladin(const Paladin& other) : Warrior(other), shieldPoints(other.shieldPoints) {}
```

`Paladin` copia a través de `Warrior`, que copia a través de `Character`. 

**El constructor parametrizado delega en los setters**, así que la validación vive en un solo lugar y no puede saltarse:

```cpp
Character::Character(std::string _name, int _level, int _hp) {
    setName(_name);
    setExperienceLevel(_level);
    setHealthPoints(_hp);
    totalCharactersCreated++;
}
```

Y validan **todo**, no solo lo que pedía el enunciado: el nombre vacío se sustituye por `"Unknown"`, y el maná, la fuerza y el escudo se ajustan a 0 si llegan negativos.

**`displayInfo()` encadenado con `virtual`/`override`** hace que `AdventuringParty::showPartyMembers()` muestre a cada miembro con su información especializada. El polimorfismo no se pedía y está bien usado, con destructor `virtual` en la base.

**El `operator<<` para `Paladin`** tampoco se pedía. Está bien declarado como `friend` y bien implementado.

**El valor por defecto `int _capacity = 5`** está en la declaración del header y no en la definición, que es donde corresponde.

---

## Lo que faltó

### `protected` en tres clases sin necesitarlo (−2 pts, bloque 2)

```cpp
class Character {
protected:
    std::string name;
    int experienceLevel;
    int healthPoints;
```

Lo mismo en `Warrior` (`meleeAttackStrength`) y en `Mage` (`manaPoints`). El enunciado permite `protected` **únicamente donde una clase derivada necesite acceder directamente**.

Revisando el código, ninguna derivada lo necesita: `Warrior::displayInfo()` llama a `Character::displayInfo()`, un **método**, no toca `name` ni `healthPoints`; `Paladin::displayInfo()` hace lo mismo con `Warrior::displayInfo()`. Los constructores usan la lista de inicialización y los setters. Es decir, todo el acceso ya pasa por la interfaz pública o protegida de métodos.

Fíjense que en `Paladin` sí usaron `private` para `shieldPoints`, y funciona igual. Ese es el criterio correcto para las otras tres.

La regla práctica: empiece siempre en `private` y suba a `protected` solo cuando el compilador se lo exija por una razón concreta. `protected` abre el atributo a **todas** las clases que hereden en el futuro, y eso es difícil de revertir.

---

## Observaciones sin efecto en la nota

- **El repositorio es público.** El enunciado de este laboratorio no exige que sea privado, así que no se penaliza. Aun así conviene saberlo: el código queda visible para cualquiera que tenga el enlace.
- **Hay dos archivos `.cpp` vacíos versionados:** `laboratorio3-enoc-raul.cpp` y `main.cpp`, ambos de 0 bytes. Todo el código está en `SolutionB.cpp`, incluido el `main`. Conviene borrarlos para que no haya dudas sobre dónde está la entrega.
- **No subieron la lista de autoevaluación.** Es obligatoria según el enunciado, aunque no otorgue puntaje.
- **Subieron el UML al repositorio** (`diagrama_uml.png`) **y** lo incluyeron en el documento. Bien: quedó donde el enunciado lo pedía.
- **El prefijo `_` en los parámetros** (`_name`, `_level`, `_hp`) es una convención válida y evita la ambigüedad con los atributos. Otra opción es nombrarlos igual y usar `this->`; ambas son correctas, solo manténganla consistente.
- **El reto opcional no se intentó.** No afecta la nota.
- **El reparto del trabajo se ve en el historial:** Raúl 6 commits, Enoc 3.

---

## Para el próximo laboratorio

Muy poco que corregir. El único hábito a ajustar es el de la visibilidad: `private` por defecto, `protected` solo cuando haga falta de verdad. Con eso la entrega era 100.

*Revisión de integridad: realizada, sin hallazgos.*
