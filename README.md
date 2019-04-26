# ICP Projekt

Implementace aplikace pro přehrávání šachových partií

### Příkazy

Makefile v rootu projektu obsahuje příkazy pro správu docker kontejneru simulujícího aktuální prostředí na Merlinu (CentOS 7) s nainstalovaným Qt.

Vytvoření docker image (spustit pouze jednou pro vytvoření)
```
$ make docker-build
```

Následuje příkaz spouštěný pro každé spuštění kontejneru. Po spuštění se ocitnete ve složce /ICP, která je volume kontejneru ze složky ./src. Změny na vašem hostu se okamžitě propíšou do docker kontejneru. Příkazy jsou rozlišeny podle OS počítače. MacOS vyžaduje k spuštění GUI aplikace z dockeru spouštěné XQuartz a socat. Zároveň vyžaduje zadat interní-ip adresu, pokud není zadána, je získána pomocí npm balíčku internal-ip-cli. Pro Linux stačí spustit make příkaz.
```
-- MACOS
$ make socat-macos # nechat běžet
$ make docker-run-macos IP=<vase_interni_ip>
-- Linux
$ make docker-run
```

Uvnitř kontejneru aplikaci zbuildíte a spustíte tímto příkazem.
```
$ make
$ ./build/chess
```

Vyčistit projekt
```
$ make clean
```

Buildit projekt lze i na host počítači stejnými příkazy v rootu projektu i v src.
```
$ make
$ make clean
```

Smazání neaktivních kontejnerů
```
$ make docker-stop
```
