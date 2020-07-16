import TADBooleano
import TADNatural

uno = sucesor cero
dos = sucesor uno
cuatro = dos `por` dos
dieciséis = cuatro `por` cuatro
doscincoseis = dieciséis `por` dieciséis
mil = (cuatro `por` doscincoseis) `menos` (dieciséis `mas` (dos `por` cuatro))

todos :: [Natural]
todos = cero : map sucesor todos

iniciar_criba :: Natural -> [Natural]
iniciar_criba n = construir_criba dos n

construir_criba :: Natural -> Natural -> [Natural]
construir_criba m n | m `menor_o_igual` n == verdadero = m : construir_criba (sucesor m) n
                    | otherwise = []

primos :: Natural -> [Natural]
primos n = procesar_criba (iniciar_criba n)

procesar_criba :: [Natural] -> [Natural]
procesar_criba [] = []
procesar_criba (p:criba) = p : procesar_criba (filter (\x -> (x `es_múltiplo_de` p) == falso) criba)

instance Show Natural where
    showsPrec n m = showsPrec n (aInteger m)
                  where aInteger m | m == cero = 0
                                   | otherwise = 1 + aInteger (predecesor m)

