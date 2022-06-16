include variables.mk

all: $(FILE).hex

$(FILE).hex: $(EXE_DIR)/$(FILE).elf
	$(COPIER) $(CP_OPTIONS) $< $(EXE_DIR)/$@

%.elf: $(OBJECTS)
	$(CC) $(LL_OPTIONS) $@ $^

%.o: %.c  
	$(CC) $(CC_OPTIONS) $@ $< 

%.o: %.S
	mkdir -p $(EXE_DIR)
	$(AS) $(CC_OPTIONS) $@ $<

upload:
	$(UPLOADER) $(U_OPTIONS)

size:
	$(PREAMBLE)$@ $(EXE_DIR)/$(FILE).elf
