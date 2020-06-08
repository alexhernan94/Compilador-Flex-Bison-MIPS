with Ada.Text_IO;
use Ada.Text_IO;
procedure Hello is
	Numero :Integer;
begin
	while Numero > 10 loop
		--BucleWhile
		Suma := Numero + 2;
	end loop;

	if Suma < 10 then
		Put_Line("Menor");
		Multiplicacion := Suma * 4;
	else
		--Hola
	    	Igual := Suma;
	end if;
end Hello