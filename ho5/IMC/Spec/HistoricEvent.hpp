//***************************************************************************
// Copyright 2017 OceanScan - Marine Systems & Technology, Lda.             *
//***************************************************************************
// Licensed under the Apache License, Version 2.0 (the "License");          *
// you may not use this file except in compliance with the License.         *
// You may obtain a copy of the License at                                  *
//                                                                          *
// http://www.apache.org/licenses/LICENSE-2.0                               *
//                                                                          *
// Unless required by applicable law or agreed to in writing, software      *
// distributed under the License is distributed on an "AS IS" BASIS,        *
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
// See the License for the specific language governing permissions and      *
// limitations under the License.                                           *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************
// Automatically generated.                                                 *
//***************************************************************************
// IMC XML MD5: 009a5046be102f40bfccc623630722a7                            *
//***************************************************************************

#ifndef IMC_HISTORICEVENT_HPP_INCLUDED_
#define IMC_HISTORICEVENT_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <ostream>
#include <string>
#include <vector>

// IMC headers.
#include <IMC/Base/Config.hpp>
#include <IMC/Base/Message.hpp>
#include <IMC/Base/InlineMessage.hpp>
#include <IMC/Base/MessageList.hpp>
#include <IMC/Base/JSON.hpp>
#include <IMC/Base/Serialization.hpp>
#include <IMC/Spec/Enumerations.hpp>
#include <IMC/Spec/Bitfields.hpp>

namespace IMC
{
  //! Historic Event.
  class HistoricEvent: public Message
  {
  public:
    //! Event Type.
    enum EventTypeEnum
    {
      //! Information.
      EVTYPE_INFO = 0,
      //! Error.
      EVTYPE_ERROR = 1
    };

    //! Event.
    std::string text;
    //! Event Type.
    uint8_t type;

    static uint16_t
    getIdStatic(void)
    {
      return 110;
    }

    static HistoricEvent*
    cast(Message* msg__)
    {
      return (HistoricEvent*)msg__;
    }

    HistoricEvent(void)
    {
      m_header.mgid = HistoricEvent::getIdStatic();
      clear();
    }

    HistoricEvent*
    clone(void) const
    {
      return new HistoricEvent(*this);
    }

    void
    clear(void)
    {
      text.clear();
      type = 0;
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::HistoricEvent& other__ = static_cast<const HistoricEvent&>(msg__);
      if (text != other__.text) return false;
      if (type != other__.type) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(text, ptr__);
      ptr__ += IMC::serialize(type, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(text, bfr__, size__);
      bfr__ += IMC::deserialize(type, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(text, bfr__, size__);
      bfr__ += IMC::deserialize(type, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return HistoricEvent::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "HistoricEvent";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 1;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(text);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "text", text, nindent__);
      IMC::toJSON(os__, "type", type, nindent__);
    }
  };
}

#endif
