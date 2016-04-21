#ifndef _REG_MSG_HXX_
#define _REG_MSG_HXX_

namespace cornerstone {
    class req_msg : public msg_base {
    public:
        req_msg(ulong term, msg_type type, int src, int dst, ulong last_log_term, ulong last_log_idx, ulong commit_idx)
            : last_log_term_(last_log_term), last_log_idx_(last_log_idx), commit_idx_(commit_idx), log_entries_(), msg_base(term, type, src,dst) {
        }
        
        virtual ~req_msg() __override__ {
            for (size_t i = 0; i < log_entries_.size(); ++i) {
                delete log_entries_[i];
            }
        }

    __nocopy__(req_msg)

    public:
        ulong get_last_log_idx() const {
            return last_log_idx_;
        }

        ulong get_last_log_term() const {
            return last_log_term_;
        }

        ulong get_commit_idx() const {
            return commit_idx_;
        }

        std::vector<log_entry*>& log_entries() {
            return log_entries_;
        }

    private:
        ulong last_log_term_;
        ulong last_log_idx_;
        ulong commit_idx_;
        std::vector<log_entry*> log_entries_;
    };
}

#endif //_REG_MSG_HXX_