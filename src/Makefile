#-----------------------------------------------------------------------------
# Purpose: Donky Kong source code
#
#------------------------------------------------------------------------------
# FPATH - is the include path to this makefile fragment
#
#-License----------------------------------------------------------------------
#Copyright (c) 2011, developer@teamboyce.com
#All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# * Redistributions of source code must retain the above copyright notice, this
#   list of conditions and the following disclaimer.
# * Redistributions in binary form must reproduce the above copyright notice,
#   this list of conditions and the following disclaimer in the documentation
#   and/or other materials provided with the distribution.
# * Neither the name of the Team Boyce Limited nor the names of its contributors
#   may be used to endorse or promote products derived from this software
#   without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

#-----------------------------------------------------------------------------
ifeq ($(INC_PART),)
# DELETE ME from top level makefile Leave me in every dir under top level and
# I will allow you to build from any point in the build system
$(if $(MAKECMDGOALS),$(MAKECMDGOALS),all):
	@$(MAKE) -C .. $@
endif

#-----------------------------------------------------------------------------
# Declare C files
CSRC += barrel.c
CSRC += barrel_four.c
CSRC += barrel_one.c
CSRC += barrel_three.c
CSRC += barrel_two.c
CSRC += font.c
CSRC += game_over.c
CSRC += kong_array.c
CSRC += mario_buttcheek.c
CSRC += mario_left.c
CSRC += mario_right.c
CSRC += project.c
CSRC += splash_screen.c
CSRC += win_screen.c


#-----------------------------------------------------------------------------
# If set to y then the include path is added to with this directory
# Delete or set to 'n' if not needed in include path
ADD_TO_INC_PATH := y
