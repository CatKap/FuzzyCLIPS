# Top-level Makefile for FZ_CLIPS and FZ_XCLIPS


all:
	@echo
	@echo Please specify fzclips, fzxclips or both.
	@echo
	@echo If you specify both, then the object files will
	@echo be cleaned up prior to both builds. 
	@echo This is because the compilation flags and options
	@echo vary for the different builds. 
	@echo
	@echo If you have built one before, and now wish to build
	@echo the other then you MUST either clean up or build
	@echo both executables for this makefile to work.
	@echo

fzclips:
	make -f Makefile.cl fz_clips

fzxclips:
	make -f Makefile.x  fz_xclips

both: 	dist_clean fzclips clean1 fzxclips

clean:
	rm -f *.o 

clean1:
	rm -f *.o

dist_clean: clean
	rm -f fz_clips
	rm -f fz_xclips

dist:
	tar -cvf FZCLIPS-6.10.tar *.c *.h Makefile Makefile.cl Makefile.x
	compress  FZCLIPS-6.10.tar
CFILES = agenda.c analysis.c argacces.c bload.c bmathfun.c bsave.c cfdef.c classcom.c classexm.c classfun.c classinf.c classini.c classpsr.c clsltpsr.c commline.c conscomp.c constrct.c constrnt.c crstrtgy.c cstrcbin.c cstrccom.c cstrcpsr.c cstrnbin.c cstrnchk.c cstrncmp.c cstrnops.c cstrnpsr.c cstrnutl.c default.c defins.c developr.c dffctbin.c dffctbsc.c dffctcmp.c dffctdef.c dffctpsr.c dffnxbin.c dffnxcmp.c dffnxexe.c dffnxfun.c dffnxpsr.c dfinsbin.c dfinscmp.c drive.c edbasic.c edmain.c edmisc.c edstruct.c edterm.c emathfun.c engine.c evaluatn.c expressn.c exprnbin.c exprnops.c exprnpsr.c extnfunc.c factbin.c factbld.c factcmp.c factcom.c factfun.c factgen.c facthsh.c factlhs.c factmch.c factmngr.c factprt.c factrete.c factrhs.c filecom.c filertr.c fuzzycom.c fuzzydef.c fuzzylhs.c fuzzymod.c fuzzypsr.c fuzzyrhs.c fuzzyutl.c generate.c genrcbin.c genrccmp.c genrccom.c genrcexe.c genrcfun.c genrcpsr.c globlbin.c globlbsc.c globlcmp.c globlcom.c globldef.c globlpsr.c immthpsr.c incrrset.c inherpsr.c inscom.c insfile.c insfun.c insmngr.c insmoddp.c insmult.c inspsr.c insquery.c insqypsr.c iofun.c lgcldpnd.c memalloc.c miscfun.c modulbin.c modulbsc.c modulcmp.c moduldef.c modulpsr.c modulutl.c msgcom.c msgfun.c msgpass.c msgpsr.c multifld.c multifun.c objbin.c objcmp.c objrtbin.c objrtbld.c objrtcmp.c objrtfnx.c objrtgen.c objrtmch.c parsefun.c pattern.c pprint.c prccode.c prcdrfun.c prcdrpsr.c prdctfun.c prntutil.c proflfun.c reorder.c reteutil.c retract.c router.c rulebin.c rulebld.c rulebsc.c rulecmp.c rulecom.c rulecstr.c ruledef.c ruledlt.c rulelhs.c rulepsr.c scanner.c sortfun.c strngfun.c strngrtr.c symblbin.c symblcmp.c symbol.c sysdep.c textpro.c tmpltbin.c tmpltbsc.c tmpltcmp.c tmpltdef.c tmpltfun.c tmpltlhs.c tmpltpsr.c tmpltrhs.c tmpltutl.c userdata.c utility.c watch.c 

lib:
	gcc -fPIC -shared -o libfzclips.so $(CFILES)

install-lib:
	sudo mv libfzclips.so /lib/
