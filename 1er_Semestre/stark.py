clave= 23412
totaladul=0
totalnin= 0
saldotarjeta=1000
validar = int(input("ingrese clave de acceso >"))
print("Bienvenido a restaurate ABC")    
while validar != 23412:
    print ("Clave incorrecta")
    validar = int(input("ingrese clave de acceso >"))
print("MENU PRINCIPAL")
print("Ingrese la opcion que desea")
opcion = int(input("Menu adulto (1), Menu niño(2), Realizar pago (3), Recarga de tarjeta (4), Salir(5) \n>"))
while opcion != 5:
    if opcion == 1:
        pregunta= "si"
        while pregunta == "si":
            seleccionadul= int(input("Seleccione un platillo del menu, Arroz a la mexicana $95 (1), Mole poblano $78 (2), Crema de brocoli $60 (3) \n>"))
            if seleccionadul == 1:
                totaladul += 95
            elif seleccionadul == 2:
                totaladul += 78
            elif seleccionadul == 3:
                totaladul += 60
            pregunta=input("quieres seguir ordenando?<si><no> >")

    if opcion == 2:
        pregunta= "si"
        while pregunta == "si":
            seleccionnin= int(input("Seleccione un platillo del menu, Nugets de pollo $56 (1), Mini pizza $90 (2), Hamburguesa $60 (3) \n>"))
            if seleccionnin == 1:
                totalnin += 56
            elif seleccionnin == 2:
                totalnin += 90
            elif seleccionnin == 3:
                totalnin += 60
            pregunta=input("quieres seguir ordenando?<si><no> >")
    
    if opcion == 3:
        
        propina= input("desea agregar propina? >")
        if propina == "si":
            porcentaje = int(input("ingrese el porcetaje de propina que desee agregar ($) >"))
            if porcentaje<10:
                print ("la propina debe de ser mayor al 10%")
                porcentaje = int(input("ingrese el porcetaje de propina que desee agregar ($) >"))
            ajuste = (porcentaje * .01) + 1
            totalgeneral = (totaladul + totalnin) * ajuste
        print ("el total por adultos es $:", totaladul)
        print ("el total por niños es $:" , totalnin)
        print ("el total general es $:" , totaladul + totalnin)
        opcion=5
    
    if opcion == 4:
        optionrecargar=input ("desea recargar su tarjeta ?<si><no> >")
        if optionrecargar.lower() == "si":
            recarga_de_tarjeta = int(input("Ingresar cantidad ($) >"))
            saldotarjeta = saldotarjeta+recarga_de_tarjeta
            print("Ahora tienes: $"+str(saldotarjeta))
            
    if opcion!=5:       
        opcion = int(input("Menu adulto (1), Menu niño(2), Realizar pago (3), Recarga de tarjeta (4), Salir(5) \n>"))
    
        

print("Total de adultos: ",totaladul)
print("Total de ninos: ",totalnin)
print ("el total general es $:" , totaladul + totalnin)